class LFUCache {
public:

//lets crack thissssss....

    int capacity;
    int size;
    //in this ques we use two maps
    // unordered_map<int,address>mp;
    unordered_map<int,list<vector<int>>::iterator>mp;  
    //key->address of list of vector{key,value,freq}

        //ordered map
    map<int,list<vector<int>>>freq;  //freq-> list of vector{key,value,freq}
    
    LFUCache(int capacity) {
        this->capacity=capacity;
        size=0;
    }
    
    void makeMostFrequentlyUsed(int key){
            auto &vec= (*(mp[key]));   //address of the present key
            //key isliye nahi lia kyuki key already present hai
            int value=vec[1];
            int f=vec[2];

            freq[f].erase(mp[key]);   //frequency jiska count f hai wahan jao or uske mp[key] jo address de raha ahai usko erase kar do

        //ab agar woh freqency or counter khali ho jaye toh uss frequency ko hi hata do now there is no need for it 
            if(freq[f].empty()){
                freq.erase(f);
            }
         
         
            f++;

            freq[f].push_front(vector<int>({key,value,f}));

            mp[key]=freq[f].begin();   //map me se bhi value ko update kar do 

    }

    int get(int key) {
        //agar key map me hai hi nahi to return -1
        if(mp.find(key)==mp.end()) return -1;

        else{
            // key present hai toh -->> uss key ki value ko get karna hai 
            //aur update bhi karna hai usko 
            
            auto &vec= (*(mp[key]));   //address of the present key
            int value=vec[1];

            makeMostFrequentlyUsed(key);

            return value;
        }
    }
    
    void put(int key, int value) {
        if(capacity==0){
            //capacity hi 0 hai LFU ki toh directly return 
            return;
        }

        // agar key pehle se present hai toh-->> uss key ki value ,freq sab ko update kar do
        if(mp.find(key)!=mp.end()){
            auto &vec= (*(mp[key]));   //address of the present key
            vec[1]=value;
            makeMostFrequentlyUsed(key);
        }

        else if(size<capacity){
            size++;
            freq[1].push_front(vector<int>{key,value,1});
            mp[key]=freq[1].begin();
        }

        else{
            //lfu capacity is full
            //now time to remove lru or lfu

            //pehla banda mila uske DLL ka access le lo or usko phir delete kar do
            auto &kaun_sa_list=freq.begin()->second;
            int key_to_delete=(kaun_sa_list.back())[0]; //ordered_map ensures that the begin() will be th eleast frequency
             kaun_sa_list.pop_back();

             if(kaun_sa_list.empty()){
                freq.erase(freq.begin()->first);
             }

             freq[1].push_front(vector<int>{key,value,1});

             mp.erase(key_to_delete); //map me se bhi delete kar do
             // or map ko update bhi kar do
             mp[key]=freq[1].begin();
            
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */