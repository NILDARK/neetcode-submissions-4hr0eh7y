class Solution {
public:
    struct Compare{
        bool operator()(const pair<int, char>& a, const pair<int, char>& b){
            return a.first<b.first;
        }
    };
    int leastInterval(vector<char>& tasks, int n) {
        int total_tasks = tasks.size();
        priority_queue<pair<int, char>, vector<pair<int, char>>, Compare> pq;
        queue<pair<int, char>> q;
        unordered_map<char, int> mp;
        vector<int> available_time(26, -1);
        for(int i=0;i<tasks.size();++i){
            mp[tasks[i]]++;
        }

        for(auto kv: mp){
            pq.push({kv.second,kv.first});
        }
        int cur_cycle = 1;
        while(!(pq.empty() && q.empty())){
            
            while(!q.empty() && available_time[q.front().second-'A'] <= cur_cycle){
                pq.push(q.front());
                q.pop();
            }

            if(pq.empty()){
                cur_cycle = available_time[q.front().second-'A'];
                continue;
            }

            pair<int, char> top = pq.top();
            top.first-=1;
            available_time[top.second-'A'] = cur_cycle + n + 1;
            if(top.first > 0){
                q.push(top);
            }
            pq.pop();
            cur_cycle++;
        }
        return cur_cycle - 1;
    }
};
