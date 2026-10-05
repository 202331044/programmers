#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Song
{
    int id;
    int play;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
//     int n = plays.size();
    
//     unordered_map<string, int> genre_count;
//     unordered_map<string, vector<int>> genre_id;
    
//     for(int id = 0; id < n; ++id)
//     {
//         string genre = genres[id];
//         int count = plays[id];
        
//         genre_count[genre] += count;
//         genre_id[genre].push_back(id);
//     }
        
    
//     vector<pair<string, int>> genres_count;
//     for(auto& it: genre_count)
//         genres_count.push_back({it.first, it.second});
    
//     sort(genres_count.begin(), genres_count.end(), 
//          [](const auto& a, const auto& b)
//           {
//               return a.second > b.second;
//           });
    
//     vector<int> answer;
    
//     for(auto& [genre, count]: genres_count)
//     {
//         vector<pair<int, int>> plays_count;
        
//         for(int id: genre_id[genre])
//             plays_count.push_back({id, plays[id]});
  
//         sort(plays_count.begin(), plays_count.end(),
//             [](const auto& a, const auto& b)
//              {
//                  if(a.second != b.second) return a.second > b.second;
//                  return a.first < b.first;
//              });
        
//         answer.push_back(plays_count[0].first);
        
//         if(plays_count.size() >= 2)
//             answer.push_back(plays_count[1].first);
//     }
        
//     return answer;
    
    int n = plays.size();
    unordered_map<string, int> genre_count;
    unordered_map<string, vector<Song>> genre_song;
    
    for(int id = 0; id < n; ++id)
    {
        string genre = genres[id];
        int play = plays[id];
        
        genre_count[genre] += play;
        genre_song[genre].push_back({id, play});
    }
    
    vector<pair<string, int>> genres_count;
    for(const auto& it: genre_count)
        genres_count.push_back({it.first, it.second});
    
    sort(genres_count.begin(), genres_count.end(),
        [](const auto& a, const auto& b)
         {
             return a.second > b.second;
         });
    
    vector<int> answer;
    
    for(const auto&[genre, total_play]: genres_count)
    {
        sort(genre_song[genre].begin(), genre_song[genre].end(),
             [](const auto& a, const auto& b)
             {
                 if(a.play != b.play) return a.play > b.play;
                 return a.id < b.id;
             });
        
        answer.push_back(genre_song[genre][0].id);
        if(genre_song[genre].size() > 1)
            answer.push_back(genre_song[genre][1].id);
    }
    
    return answer;
}
