/*

    Limitaion:
        Only for int (templateNot used)
            - 0 to x
        only for undirectedGraph
        ///! no Try Cath Used

*/

#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph
{
private:
    int nVertexs;
    int nEdges;
    list<pair<int, list<int>>> graphList;

    // helper: find vertex
    auto findVertex(int x)
    {
        for (auto it = graphList.begin(); it != graphList.end(); ++it)
        {
            if (it->first == x)
                return it;
        }
        return graphList.end();
    }

public:
    Graph()
    {
        this->nVertexs = 0;
        this->nEdges = 0;
    }

    void addVertex()
    {
        cout << "Enter Vertex : ";
        int x;
        cin >> x;

        if (findVertex(x) != graphList.end())
        {
            cout << "Vertex already exists !" << endl;
            return;
        }

        graphList.push_back({x, list<int>()});
        nVertexs++;

        cout << "Added SuccesFully !" << endl;
    }

    void addEdge()
    {
        cout << "Enter Two Nodes to Connect : ";
        int x, y;
        cin >> x >> y;

        auto vx = findVertex(x);
        auto vy = findVertex(y);

        if (vx == graphList.end() || vy == graphList.end())
        {
            cout << "Vertex does not exist !" << endl;
            return;
        }

        // undirected graph
        vx->second.push_back(y);
        vy->second.push_back(x);

        nEdges++;
        cout << "Edge Added Successfully !" << endl;
    }

    void printGraph()
    {
        cout << "\nGraph Adjacency List:\n";
        for (auto &node : graphList)
        {
            cout << node.first << " : ";
            for (int adj : node.second)
                cout << adj << " ";
            cout << endl;
        }
    }

    // ================= BFS =================
    void BFS(int start)
    {
        auto it = findVertex(start);
        if (it == graphList.end())
        {
            cout << "Invalid start vertex !" << endl;
            return;
        }

        list<int> visited;
        queue<int> q;

        q.push(start);
        visited.push_back(start);

        cout << "BFS Traversal : ";

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";

            auto curr = findVertex(node);
            for (int neighbor : curr->second)
            {
                bool seen = false;
                for (int v : visited)
                    if (v == neighbor)
                        seen = true;

                if (!seen)
                {
                    visited.push_back(neighbor);
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // ================= DFS =================
    void DFSUtil(int node, list<int> &visited)
    {
        cout << node << " ";
        visited.push_back(node);

        auto curr = findVertex(node);
        for (int neighbor : curr->second)
        {
            bool seen = false;
            for (int v : visited)
                if (v == neighbor)
                    seen = true;

            if (!seen)
                DFSUtil(neighbor, visited);
        }
    }

    void DFS(int start)
    {
        auto it = findVertex(start);
        if (it == graphList.end())
        {
            cout << "Invalid start vertex !" << endl;
            return;
        }

        list<int> visited;
        cout << "DFS Traversal : ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

enum Control
{
    DEFAULT_VAL,
    ADD_VERTEX,
    ADD_EDGE,
    PRINT_GRAPH,
    BFS_TRAVERSAL,
    DFS_TRAVERSAL,
    EXIT
};

int main()
{
    Graph g;
    Control controlVariable = DEFAULT_VAL;

    while (controlVariable != EXIT)
    {
        switch (controlVariable)
        {
        case DEFAULT_VAL:
        {
            cout << "\nMain Menu:\n";
            cout << "0 DEFAULT\n1 ADD_VERTEX\n2 ADD_EDGE\n3 PRINT_GRAPH\n4 BFS\n5 DFS\n6 EXIT\n";
            int input;
            cin >> input;
            controlVariable = static_cast<Control>(input);
            break;
        }

        case ADD_VERTEX:
            g.addVertex();
            controlVariable = DEFAULT_VAL;
            break;

        case ADD_EDGE:
            g.addEdge();
            controlVariable = DEFAULT_VAL;
            break;

        case PRINT_GRAPH:
            g.printGraph();
            controlVariable = DEFAULT_VAL;
            break;

        case BFS_TRAVERSAL:
        {
            int start;
            cout << "Enter start vertex for BFS : ";
            cin >> start;
            g.BFS(start);
            controlVariable = DEFAULT_VAL;
            break;
        }

        case DFS_TRAVERSAL:
        {
            int start;
            cout << "Enter start vertex for DFS : ";
            cin >> start;
            g.DFS(start);
            controlVariable = DEFAULT_VAL;
            break;
        }

        case EXIT:
            cout << "Termination Graph !" << endl;
            break;

        default:
            cout << "Wrong Input !" << endl;
            controlVariable = DEFAULT_VAL;
        }
    }

    cout << "Program Terminated !" << endl;
    return 0;
}
