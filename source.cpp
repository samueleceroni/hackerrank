#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int is_default(int i, int r_q, int c_q, vector<vector<int> > ar){
    return (ar[i][0] == r_q && ar[i][1] == c_q)?1:0;
}

void updateObstacles(int r_q, int c_q, int r_o, int c_o, vector<vector<int> >ob_pos){
    //fout <<r_q<<"  "<<c_q<<endl<< r_o <<"  "<<c_o<<endl;
    // same row left
    if(r_o == r_q && c_o < c_q && (ob_pos[0][1]<c_o || ob_pos[0][1] == c_q)){
        ob_pos[0][1] = c_o;
        return;
    }
    // same row right
    if(r_o == r_q && c_o > c_q && (ob_pos[4][1]>c_o || ob_pos[4][1] == c_q)){
        ob_pos[4][1] = c_o;
        return;
    }
    // same column up
    if(c_o == c_q && r_o > r_q && (ob_pos[2][0]>r_o || ob_pos[2][0] == r_q)){
        ob_pos[2][0] = r_o;
        return;
    }
    // same column down
    if(c_o == c_q && r_o < r_q && (ob_pos[6][0]<r_o || ob_pos[6][0] == r_q)){
        ob_pos[6][0] = r_o;
        return;
    }
    
    // diagonal '/' up
    if(r_o-c_o == r_q-c_q && r_o > r_q && (ob_pos[3][0]>r_o || ob_pos[3][0]== r_q)){
        ob_pos[3][0] = r_o;
        ob_pos[3][1] = c_o;
        return;
    }
    // diagonal '/' down
    if(r_o-c_o == r_q-c_q && r_o < r_q && (ob_pos[7][0]<r_o || ob_pos[7][0]== r_q)){
        ob_pos[7][0] = r_o;
        ob_pos[7][1] = c_o; 
        return;
    }
    // diagonal '\' up
    if(r_o+c_o == r_q+c_q && r_o > r_q && (ob_pos[1][0]>r_o || ob_pos[1][0]== r_q)){
        ob_pos[1][0] = r_o;
        ob_pos[1][1] = c_o;
        return;
    }
    // diagonal '\' down
    if(r_o+c_o == r_q+c_q && r_o < r_q && (ob_pos[5][0]<r_o || ob_pos[5][0]== r_q)){
        ob_pos[5][0] = r_o;
        ob_pos[5][1] = c_o; 
        return;
    }

}


int queensAttack(int n, int k, int r_q, int c_q, vector < vector<int> > obstacles) {
    // get saved nearest obstacle position since they can occupy only the 8 directions of the queen moves
    // 0-> left
    // 1-> left up
    // 2-> up
    // 3-> up right
    // 4-> right 
    // 5-> right down
    // 6-> down
    // 7-> down left
    // they are all initialized with queen position, so that i know there is no obstacle if positions coincide
    
    // fout << n <<endl<<k<<endl<<r_q<<c_q;
    // fflush(stdin);
    // getchar();

    vector<vector<int> > ob_pos (8,vector<int> (2)={r_q,c_q});
    // for (int i=0; i<k; i++)
    // fout << ob_pos[1][0] <<"  "<<ob_pos[1][1]<<endl;
    // fflush(stdin);
    // getchar();

    int sol=0;

    // update the position of the obstacles which prevent queen movements
    for (int i=0; i<k; i++)
        updateObstacles(r_q, c_q, obstacles[i][0], obstacles[i][1], ob_pos);

    for (int i=0; i<8; i++)
        if(ob_pos[i][0] == r_q && ob_pos[i][1] == c_q)
            sol++;

    return sol;

}

int main() {
    int n;
    int k;
    fin >> n >> k;
    int r_q;
    int c_q;
    fin >> r_q >> c_q;
    vector< vector<int> > obstacles(k,vector<int>(2));
    for(int obstacles_i = 0;obstacles_i < k;obstacles_i++){
       for(int obstacles_j = 0;obstacles_j < 2;obstacles_j++){
          fin >> obstacles[obstacles_i][obstacles_j];
       }
    }
    int result = queensAttack(n, k, r_q, c_q, obstacles);
    fout << result << endl;
    return 0;
}
