Intuition :
   - LRU Cache follows the principle of Least Recently Used where the most recently accessed element should be kept in the front, and the least used should be discarded when the capacity is exceeded.
   - Double Linked List (DLL) is used to store the keys in order of usage. This allows O(1) insertion/deletion of elements.
   - A map (mapp) stores the key-value pair along with the iterator pointing to its position in the list. This provides O(1) access to any key for both retrieval and updating.
   - On each access (get or put), the accessed key is moved to the front of the DLL to indicate recent use.

  
Approach : 
   - Use a doubly linked list (DLL) to track the order of key usage and a hash map to store key-value pairs and their position in the DLL.
   - When accessing or updating a key, move it to the front of the list to mark it as most recently used.
   - On a get operation, return the value if the key exists; otherwise, return -1.
   - On a put operation, insert or update the key, and if the cache exceeds capacity, remove the least recently used key (from the back of the list).


CODE :-

class LRUCache {
public:

    list<int> dll;
    map<int , pair<list<int>::iterator , int>> mapp;

    int n;
    LRUCache(int capacity) {
        
        n = capacity;
    }
    
    void mostRecentlyUsed(int key){

        dll.erase(mapp[key].first);
        dll.push_front(key);
        mapp[key].first = dll.begin();
    }
    int get(int key) {
        

        if(mapp.find(key) == mapp.end()){
            return -1;
        }
       
       mostRecentlyUsed(key);

       return mapp[key].second;

    }
    
    void put(int key, int value) {
        
        if(mapp.find(key) != mapp.end()){

            mapp[key].second = value;
            mostRecentlyUsed(key);
        }
        else{

            dll.push_front(key);
            mapp[key] = {dll.begin() , value};
            n--;
        }

        if(n < 0){
            
            int deletedKey = dll.back();
            mapp.erase(deletedKey);
            dll.pop_back();
            n++;

        }
    }
};
