#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<char>>&board){
    cout<<"     |     |     "<<endl;
    cout<<"  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;

    cout<<"     |     |     "<<endl;
    cout<<"  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;

    cout<<"     |     |     "<<endl;
    cout<<"  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  "<<endl;
    cout<<"     |     |     "<<endl;
}

bool haveWon(vector<vector<char>>&board, char player){
    //check row wise
    for(int row = 0; row < board.size(); row++){
        if((board[row][0]==player && board[row][1]==player) && board[row][2]==player){
            return true;
        }
    }
    //check column wise
    for(int col = 0; col < board[0].size(); col++){
        if((board[0][col]==player && board[1][col]==player) && (board[2][col]==player)){
            return true;
        }
    }
    //check primary diagonal wise
    if((board[0][0]==player && board[1][1]==player) && board[2][2]==player){
        return true;
    }
    //check secondary diagonal wise
    if((board[0][2]==player && board[1][1]==player) && board[2][0]==player){
        return true;
    }
    return false;
}


int main(){
    vector<vector<char>>board(3, vector<char>(3, ' '));
    int row , col;
    bool gameOver = false;
    char player = 'X';
    
    while(!gameOver){
        print(board);//print the board
        cout<<"Player "<<player<<" enter row then column: "<<endl;
        cin>>row;
        cin>>col;
        row = row -1;
        col = col -1;
        if(board[row][col]==' '){//if the location is empty
            board[row][col] = player;
            gameOver = haveWon(board, player);
            if(gameOver){
                cout<<endl;
                cout<<"************************!!!CONGRATULATIONS!!!*************************"<<endl;
                cout<<endl;

                cout<<"Player "<<player<<" you have won the game."<<endl;
            }
            else{
                player = (player=='X')?'O':'X';//switch the player
            }
        }
        else{
            cout<<"Oops!! Invalid location, Try 1 to 3!"<<endl;
        }
    }
    print(board);

    return 0;
}