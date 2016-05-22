//uri:	https://leetcode.com/problems/reconstruct-itinerary/

/*
 *	图论问题。此题为有向图问题，先求出从"JFK"出发所有包含环的通路，然后再去求没有环的通路。
 *	空间复杂度：O(n).
 *	时间复杂度：O(nlogn).
 * */

inline bool cmp(const pair<string, string>& p, const pair<string, string>& q) {
    if ( p.first != q.first ) { return p.first < q.first; }
    return p.second < q.second;
}

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        if ( tickets.size() < 1 ) { return vector<string>(); }
        
        sort(tickets.begin(), tickets.end(), cmp);
        
        string ticket = "";
        unordered_map<string, int> string_to_int;
        for ( int i = 0; i < tickets.size(); ++ i ) {
            if ( ticket != tickets[i].first ) {
                string_to_int[tickets[i].first] = i;
                ticket = tickets[i].first;
            }
        }
        
        stack<string> st;
        st.push("JFK");
        vector<string> path;
        
        while ( !st.empty() ) {
            string ticket = st.top();
            auto itr = string_to_int.find(ticket);
            
            if ( itr == string_to_int.end() || itr -> second >= tickets.size() || tickets[itr -> second].first != ticket ) {
                st.pop();
                path.push_back(ticket);
            } else {
                st.push(tickets[itr -> second].second);
                itr -> second += 1;
            }
        }
        
        reverse(path.begin(), path.end());
        
        return path;
    }
};
