class Twitter {
private:
    int time;
    int maxFeed;
    unordered_map<int, deque<pair<int,int>> > tweets;
    //           user id        time  tweetid
    unordered_map<int, list<int> > following;
    //            user followee
    unordered_map<long,  list<int>::iterator > follower_followee;
    
    long getKey(int followerId, int followeeId) {
        return (long)followerId << 32 | (long)followeeId;
    }
public:
    Twitter() {
        time = 0;
        maxFeed = 10;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
        if(tweets[userId].size() > maxFeed) {
            tweets[userId].pop_front();
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        for(auto tweet: tweets[userId]) {
            pq.push(tweet);
        }
        
        for(auto followee: following[userId]) {
            for(auto tweet: tweets[followee]) {
                pq.push(tweet);
            }
        }
        
        while(!pq.empty()) {
            if(res.size() == maxFeed)
                break;
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            if(follower_followee.find(getKey(followerId,followeeId)) == follower_followee.end()) {
                // i.e; the relationship already doesn't exist
                following[followerId].push_front(followeeId);
                auto key = getKey(followerId, followeeId);
                follower_followee[key] = following[followerId].begin();
            }
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        auto key = getKey(followerId, followeeId);
        if(follower_followee.find(key) != follower_followee.end()){
            following[followerId].erase(follower_followee[key]);
            follower_followee.erase(key);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */


// 355 LEETCODE

// Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

// Implement the Twitter class:

// Twitter() Initializes your twitter object.
// void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
// List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
// void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
// void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.




