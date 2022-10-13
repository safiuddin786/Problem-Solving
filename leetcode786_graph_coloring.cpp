#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    vector<vector<int>> graph;

    int size = graph.size();
    int colors[size];

    for(int i=0; i<size; i++)
        colors[i]=0;

    // bfs
    queue<int> bfs;

    for(int index=0; index < graph.size(); index++){
        if(colors[index] == 0)
            bfs.push(index);
        while(!bfs.empty()){
            int chosenColor=0;
            int currIndex = bfs.front();
            bfs.pop();

            for(int i=0; i<graph[currIndex].size(); i++){
                int nextPos = graph[currIndex][i];

                if(colors[nextPos] != 0){
                    if(chosenColor == 0){
                        chosenColor = (colors[nextPos] == 1)?2:1;
                    }else if(chosenColor == colors[nextPos]){
                        chosenColor = -1;
                        break;
                    }
                }else{
                    bfs.push(nextPos);
                }
            }
            if(chosenColor == -1){
                cout<<"false";
                break;
            }else if(chosenColor == 0){
                colors[currIndex] = 1;
            }else{
                colors[currIndex] = chosenColor;
            }
        }
    }
    cout<<"true";//instead return
        
}