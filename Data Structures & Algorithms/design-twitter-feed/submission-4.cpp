class Twitter {
public:
    Twitter() {
        ticks = 0;
        max_users = 500;
        followers.resize(max_users+1);
        followees.resize(max_users+1);
        userwise_tweets.resize(max_users+1);
        news_feed.resize(max_users+1);
        
        for(int i=1;i<=max_users;++i){
            followers[i].insert(i);
            followees[i].insert(i);
        }
    }
    
    void postTweet(int userId, int tweetId) {
        userwise_tweets[userId].push_back({ticks, tweetId});

        for(int follower: followers[userId]){
            auto &pq = news_feed[follower];
            if(pq.size()>=10) pq.pop();
            pq.push({ticks, {tweetId, userId}});
        }

        ticks++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        auto pq = news_feed[userId];
        while(!pq.empty()){
            ans.push_back(pq.top().second.first);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId, bool allow_self = false) {
        if(!allow_self && followerId==followeeId) return;
        if(followees[followerId].find(followeeId) != followees[followerId].end()) return;
        followers[followeeId].insert(followerId);
        followees[followerId].insert(followeeId);
        auto &pq = news_feed[followerId];
        int cur = userwise_tweets[followeeId].size()-1;
        while(cur>=0 && pq.size()<10){
            auto tweet = userwise_tweets[followeeId][cur];
            pq.push({tweet.first, {tweet.second, followeeId}});
            cur--;
        }

        while(cur>=0 && !pq.empty() && pq.top().first<userwise_tweets[followeeId][cur].first){
            auto tweet = userwise_tweets[followeeId][cur];
            if(pq.size()>=10){
                pq.pop();
            }
            pq.push({tweet.first, {tweet.second, followeeId}});
            cur--;
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId) return;
        if(followees[followerId].find(followeeId) == followees[followerId].end()) return;
        followers[followeeId].erase(followerId);
        
        auto new_followees = followees[followerId];
        followees[followerId].clear();
        news_feed[followerId] = priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> ();

        for(int followee: new_followees){
            if(followee == followeeId) continue;
            follow(followerId, followee, true);
        }
    }
private:
    struct Compare {
        bool operator()(const pair<int, pair<int,int>>& a, const pair<int,pair<int,int>> & b){
            return a.first>b.first;
        }
    };
    size_t ticks;
    size_t max_users;
    vector<unordered_set<int>> followers;
    vector<unordered_set<int>> followees;
    vector<vector<pair<int, int>>> userwise_tweets;
    vector<priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare>> news_feed;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */