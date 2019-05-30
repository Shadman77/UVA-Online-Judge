#include<iostream>
#include<queue>
//#include<cstdio>
//FILE *fp;
using namespace std;
char visited[220], tempChar;//color of nodes
int adjacencyList[220][220], numOfNodes, numOfAdjacentNodes[220], numOfEdges;
int u, v;
int i,j;//counter

queue<int> bfsQueue;

void addEdge()
{
    for(i = 0; i < numOfEdges; i++)
    {
        cin >> u >> v;
        adjacencyList[u][numOfAdjacentNodes[u]] = v;
        numOfAdjacentNodes[u]++;
        adjacencyList[v][numOfAdjacentNodes[v]] = u;
        numOfAdjacentNodes[v]++;
    }
}

int bfs()
{
    visited[0] = 'b';//here we always start from node 0
    bfsQueue.push(0);
    while(bfsQueue.size()!=0)
    {
        if(visited[bfsQueue.front()] == 'b')//this is not required
            tempChar = 'r';
        else
            tempChar = 'b';

        for(i = 0; i < numOfAdjacentNodes[bfsQueue.front()]; i++)
        {
            if(visited[adjacencyList[bfsQueue.front()][i]]=='\0')
            {

                bfsQueue.push(adjacencyList[bfsQueue.front()][i]);
                visited[bfsQueue.back()] = tempChar;
            }
            else if(visited[adjacencyList[bfsQueue.front()][i]]!=tempChar)//need to make some changes here
                return 1;

        }
        bfsQueue.pop();
    }
    return 0;
}

int main()
{
    fp = fopen("test.txt","a");
    while(1)
    {
        cin >> numOfNodes;
        if(numOfNodes == 0)
            break;

        for(i = 0; i < numOfNodes; i++)
        {
            visited[i] = '\0';
            numOfAdjacentNodes[i] = 0;
        }
        cin >> numOfEdges;

        addEdge();

        while(!bfsQueue.empty())
            bfsQueue.pop();
        if(bfs() == 0){
            cout << "BICOLORABLE." << endl;
            //fprintf(fp,"BICOLORABLE.\n");
        }
        else{
            cout << "NOT BICOLORABLE." << endl;
            //fprintf(fp,"NOT BICOLORABLE.\n");
        }
    }
    //fclose(fp);
    return 0;
}
