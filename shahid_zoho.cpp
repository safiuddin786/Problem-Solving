#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
void moveDS(vector<vector<string>> &a, int &size, vector<int> ball_pos, int &brick_count, bool &extend_brick);
// destroy all bricks rows except the last and first bricks
void moveDE(vector<vector<string>> &a, int &size, vector<int> ball_pos, int &brick_count, bool &extend_brick){
    a[ball_pos[0]][ball_pos[1]] = "0";
    for(int i=1; i<size-1; i++){
        if(a[ball_pos[0]][i] == "DS" || a[ball_pos[0]][i] == "ds"){
            brick_count--;
            vector<int> temp{ball_pos[0],i};
            moveDS(a, size, temp, brick_count, extend_brick);
        }
        else if(a[ball_pos[0]][i] == "B" || a[ball_pos[0]][i] == "b"){
            brick_count--;
            int pos = size/2;
            if(extend_brick){
                while(a[size-1][pos] != "G" || a[size-1][pos] != "G") pos++;
                if(pos != size-1) a[size-1][pos] = "_";
                extend_brick = !extend_brick;
            }else{
                while(a[size-1][pos] != "G" || a[size-1][pos] != "G") pos--;
                if(pos != 0) a[size-1][pos] = "_";
                extend_brick = !extend_brick;
            }
        }else if(a[ball_pos[0]][i] == "DE" || a[ball_pos[0]][i] == "de" || a[ball_pos[0]][i] == "1"){
            brick_count--;
        }
        a[ball_pos[0]][i] = "0";
    }
}
// destroy all the surrounding bricks except the Wall
void moveDS(vector<vector<string>> &a, int &size, vector<int> ball_pos, int &brick_count, bool &extend_brick){
    a[ball_pos[0]][ball_pos[1]] = "0";
    int pos[8][2] = {
        {ball_pos[0]-1, ball_pos[1]-1},
        {ball_pos[0]-1, ball_pos[1]},
        {ball_pos[0]-1, ball_pos[1]+1},
        {ball_pos[0]+1, ball_pos[1]+1},
        {ball_pos[0]+1, ball_pos[1]},
        {ball_pos[0]+1, ball_pos[1]-1},
        {ball_pos[0], ball_pos[1]+1},
        {ball_pos[0], ball_pos[1]-1}
        };
    for(int i=0; i<8; i++){
        if(a[pos[i][0]][pos[i][1]] == "DS" || a[pos[i][0]][pos[i][1]] == "ds"){
            brick_count--;
            vector<int> temp{pos[i][0], pos[i][1]};
            moveDS(a, size, temp, brick_count, extend_brick);
        }
        else if(a[pos[i][0]][pos[i][1]] == "B" || a[pos[i][0]][pos[i][1]] == "b"){
            brick_count--;
            int pos = size/2;
            if(extend_brick){
                while(a[size-1][pos] != "G" || a[size-1][pos] != "G") pos++;
                if(pos != size-1) a[size-1][pos] = "_";
                extend_brick = !extend_brick;
            }else{
                while(a[size-1][pos] != "G" || a[size-1][pos] != "G") pos--;
                if(pos != 0) a[size-1][pos] = "_";
                extend_brick = !extend_brick;
            }
        }
        else if(a[pos[i][0]][pos[i][1]] == "DE" || a[pos[i][0]][pos[i][1]] == "de"){
            brick_count--;
            vector<int> temp{pos[i][0], pos[i][1]};
            moveDE(a, size, temp, brick_count, extend_brick);
        }
        else if(a[pos[i][0]][pos[i][1]] == "1") brick_count--;
        a[pos[i][0]][pos[i][1]] = "0";
    }
}
int main(){
    int size;
    cout<<"Enter size of the NxN matrix: ";
    cin>>size;
    cout<<endl;
    // matrix
    vector<vector<string>> a;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            // set the walls
            if(j==0) a.push_back({"W"});
            else if(i==0 || j==size-1) a[i].push_back("W");
            else if(i == size-1) a[i].push_back("G");
            else a[i].push_back("0");
        }
    }
    // setting the starting point
    a[size-1][size/2] = "o";
    vector<int> ball_pos{size-1, size/2};
    // getting the positions of the bricks
    bool check = true;
    int brick_count=0;
    while(check){
        cout<<"Enter the brick's position and the brick type: ";
        int i,j;
        string item;
        char decision;
        cin>>i>>j;
        cin>>item;
        a[i][j] = item;
        cout<<"Do you want to Coninute('Y' or 'N')?";
        cin>>decision;
        if(decision == 'Y' || decision == 'y') check = true;
        else check = false;
        brick_count++;
    }
    // ball count
    int count;
    cout<<"Enter ball count: ";
    cin>>count;
    // right or left extention if true then right and switch and viceversa
    bool extend_brick = true;

// testing the matrix
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }


    // All parameters ready
    // starting the game now
    while(true){
        string move;
        cout<<"Enter the direction in which the ball needs to traverse: ";
        cin>>move;
        if(move == "ST" || move == "st"){
            ball_pos[0]--;
            // traverse
            while(a[ball_pos[0]][ball_pos[1]] == "0") ball_pos[0]--;
        }else if(move == "LD" || move == "ld"){
            ball_pos[0]--;
            ball_pos[1]--;
            // traverse in left diagonal
            while(a[ball_pos[0]][ball_pos[1]] == "0"){
                ball_pos[0]--;
                ball_pos[1]--;
            }
        }else if(move == "RD" || move == "rd"){
            ball_pos[0]--;
            ball_pos[1]++;
            // traverse in right diagonal
            while(a[ball_pos[0]][ball_pos[1]] == "0"){
                ball_pos[0]--;
                ball_pos[1]++;
            }
        }else{
            cout<<"Illegal move try again: ";
            continue;
        }
        // if it's wall check if it's a right or left or straight one
        if(a[ball_pos[0]][ball_pos[1]] == "W"){
            // hit on the straight wall
            if(ball_pos[0] == 0){
                if(a[size-1][ball_pos[1]] == "G"){
                    count--;
                    // set the initial ball position
                    ball_pos[0] = size-1;
                    ball_pos[1] = size/2;
                }else{
                    ball_pos[0] = size-1;
                }
            }
            // hit on the left wall
            else if(ball_pos[1] == 0){
                ball_pos[1]++;
                while(a[ball_pos[0]][ball_pos[1]] == "0"){
                    ball_pos[1]++;
                }
                // if it hit on the brick then start
                while(a[ball_pos[0]][ball_pos[1]] != "W"){
                    if(a[ball_pos[0]][ball_pos[1]] == "DE" || a[ball_pos[0]][ball_pos[1]] == "de"){
                        brick_count--;
                        moveDE(a, size, ball_pos, brick_count, extend_brick);
                    }else if(a[ball_pos[0]][ball_pos[1]] == "DS" || a[ball_pos[0]][ball_pos[1]] == "ds"){
                        brick_count--;
                        moveDS(a, size, ball_pos, brick_count, extend_brick);
                    }else if(a[ball_pos[0]][ball_pos[1]] == "B" || a[ball_pos[0]][ball_pos[1]] == "b"){
                        a[ball_pos[0]][ball_pos[1]] = "0";
                        int pos = size/2;
                        if(extend_brick){
                            while(a[size-1][pos] != "G" || a[size-1][pos] != "G") pos++;
                            if(pos != size-1) a[size-1][pos] = "_";
                            extend_brick = !extend_brick;
                        }else{
                            while(a[size-1][pos] != "G" || a[size-1][pos] != "G") pos--;
                            if(pos != 0) a[size-1][pos] = "_";
                            extend_brick = !extend_brick;
                        }
                        brick_count--;
                    }else if(a[ball_pos[0]][ball_pos[1]] == "1"){
                        brick_count--;
                        a[ball_pos[0]][ball_pos[1]] = "0";
                    }
                    ball_pos[1]++;
                }
                count--;
                ball_pos[0] = size-1;
                ball_pos[1] = size/2;
            }
            // hit on the right wall
            else if(ball_pos[1] == size-1){
                ball_pos[1]--;
                while(a[ball_pos[0]][ball_pos[1]] == "0"){
                    ball_pos[1]--;
                }
                // if it hit on the brick then start
                while(a[ball_pos[0]][ball_pos[1]] != "W"){
                    if(a[ball_pos[0]][ball_pos[1]] == "DE" || a[ball_pos[0]][ball_pos[1]] == "de"){
                        brick_count--;
                        moveDE(a, size, ball_pos, brick_count, extend_brick);
                    }else if(a[ball_pos[0]][ball_pos[1]] == "DS" || a[ball_pos[0]][ball_pos[1]] == "ds"){
                        brick_count--;
                        moveDS(a, size, ball_pos, brick_count, extend_brick);
                    }else if(a[ball_pos[0]][ball_pos[1]] == "B" || a[ball_pos[0]][ball_pos[1]] == "b"){
                        a[ball_pos[0]][ball_pos[1]] = "0";
                        int pos = size/2;
                        if(extend_brick){
                            while(a[size-1][pos] != "G" || a[size-1][pos] != "G") pos++;
                            if(pos != size-1) a[size-1][pos] = "_";
                            extend_brick = !extend_brick;
                        }else{
                            while(a[size-1][pos] != "G" || a[size-1][pos] != "G") pos--;
                            if(pos != 0) a[size-1][pos] = "_";
                            extend_brick = !extend_brick;
                        }
                        brick_count--;
                    }else if(a[ball_pos[0]][ball_pos[1]] == "1"){
                        brick_count--;
                        a[ball_pos[0]][ball_pos[1]] = "0";
                    }
                    ball_pos[1]--;
                }
                count--;
                ball_pos[0] = size-1;
                ball_pos[1] = size/2;
            }
        }
        // if it's a DE brick then call DE method
        else if(a[ball_pos[0]][ball_pos[1]] == "DE" || a[ball_pos[0]][ball_pos[1]] == "de"){
            brick_count--;
            moveDE(a, size, ball_pos, brick_count, extend_brick);
            if(a[size-1][ball_pos[1]] == "G"){
                count--;
                ball_pos[0] = size-1;
                ball_pos[1] = size/2;
            }else{
                ball_pos[0] = size-1;
            }
        }
        // if it's a DS brick then call DS method
        else if(a[ball_pos[0]][ball_pos[1]] == "DS" || a[ball_pos[0]][ball_pos[1]] == "ds"){
            brick_count--;
            moveDS(a, size, ball_pos, brick_count, extend_brick);
            if(a[size-1][ball_pos[1]] == "G"){
                count--;
                ball_pos[0] = size-1;
                ball_pos[1] = size/2;
            }else{
                ball_pos[0] = size-1;
            }
        }
        // if it's a B brick then extend using extend_brick
        else if(a[ball_pos[0]][ball_pos[1]] == "B"){
            brick_count--;
            a[ball_pos[0]][ball_pos[1]] = "0";
            int pos = size/2;
            if(extend_brick){
                while(a[size-1][pos] != "G" || a[size-1][pos] != "G") pos++;
                if(pos != size-1) a[size-1][pos] = "_";
                extend_brick = !extend_brick;
            }else{
                while(a[size-1][pos] != "G" || a[size-1][pos] != "G") pos--;
                if(pos != 0) a[size-1][pos] = "_";
                extend_brick = !extend_brick;
            }
            if(a[size-1][ball_pos[1]] == "G"){
                count--;
                ball_pos[0] = size-1;
                ball_pos[1] = size/2;
            }else{
                ball_pos[0] = size-1;
            }
        }
        // if it's a normal brick
        else{
            brick_count--;
            a[ball_pos[0]][ball_pos[1]] = "0";
            if(a[size-1][ball_pos[1]] == "G"){
                count--;
                ball_pos[0] = size-1;
                ball_pos[1] = size/2;
            }else{
                ball_pos[0] = size-1;
            }
        }
        // testing the matrix
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"ball count: "<<count<<endl;

        if(brick_count <= 0){
            cout<<"You win HURRAY..!!"<<endl;
            break;
        }
        if(count <= 0){
            cout<<"Game over!"<<endl;
            break;
        }
    }
    return 0;
}