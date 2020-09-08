#include "ED.hpp"

ED::ED(string a, string b){
    copy(a.begin(), a.end(), back_inserter(vecA));
    copy(b.begin(), b.end(), back_inserter(vecB));
}

//used Lambda for extra credit.
/*int ED::penalty(char a, char b){
    if (a == b) return 0;
    return 1;
}*/

/*int ED::min(int a, int b,int c){
    if(a <= b && a <= c) return a;
    if(b <= a && b <= c) return b;
    return c;
}*/

int ED::OptDistance(){
    auto lambdaPenalty=[](char a, char b) { 
        if(a==b)return 0;
        return 1; 
    };

    auto lambdaMin=[](int a, int b, int c){
        if(a <= b && a <= c) return a;
        if(b <= a && b <= c) return b;
        return c;
    };

    for (unsigned int i = 0; i < vecA.size()+1; i++){
        vecMatrix.push_back(vector<int>());
        for (unsigned int j =0; j < vecB.size()+1; j++)
        vecMatrix[i].push_back(0);
    }

    int temp = 0;
    for(int i = int(vecB.size()); i >= 0; i--){
        vecMatrix[vecA.size()][i]=temp;
        temp +=2;
    }

    temp=0;
    for(int j = int(vecA.size()); j >= 0; j--){
        vecMatrix[j][vecB.size()] = temp;
        temp +=2;
    }

    for (int i = int(vecA.size())-1; i >= 0; i--)
        for (int j = int(vecB.size())-1; j >= 0; j--)
            vecMatrix[i][j] = lambdaMin(vecMatrix[i+1][j+1] + lambdaPenalty(vecA[i],vecB[j]), vecMatrix[i+1][j]+2, vecMatrix[i][j+1]+2);

    return vecMatrix[0][0]; 
}

string ED::Alignment(){
    string a="x y cost \n";
    int i = 0;
    int j = 0;

    while (i != int(vecA.size()) || j != int(vecB.size())){
        if (vecA[i] == vecB[j]){
            a += vecA[i];
            a += " ";
            a += vecB[j];
            a += " 0\n";
            i++;
            j++;
        }
        else if (vecMatrix[i][j] == vecMatrix[i+1][j+1] + 1){
            a += vecA[i];
            a += " ";
            a += vecB[j];
            a += " 1\n";
            i++;
            j++;
        }
        else if(vecMatrix[i][j] == vecMatrix[i+1][j] + 2){
            a += vecA[i];
            a += " ";
            a += "_";
            a += " 2\n";
            i++;
        }
        else if(vecMatrix[i][j] == vecMatrix[i][j+1] + 2){
            a += "_";
            a += " ";
            a += vecB[j];
            a += " 2\n";
            j++;
        }
    }; 
    return a;
}

int main(){
    string a,b;
    cin >> a >> b;
    ED ed(a,b);

    sf::Clock clock;
    sf::Time t;
    cout << "Edit distance = " << ed.OptDistance();
    cout << endl;
    cout << ed.Alignment();

    t = clock.getElapsedTime();
    cout << "Execution time is " << t.asSeconds() << " seconds.\n";
    
    return EXIT_SUCCESS;
}