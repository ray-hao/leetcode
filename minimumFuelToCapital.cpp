class Solution {
public:

    // struct node
    // int cars
    // int riders
    // vector<int> neighbors
    struct node {
        double cars = 0;
        double riders = 1;
        bool visited = false;
        vector<int> neighbors;
    };

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        node* nodes = new node[roads.size() + 1];

        for (auto it : roads) {
            int a = it[0];
            int b = it[1];

            nodes[a].neighbors.push_back(b);
            nodes[b].neighbors.push_back(a);
        }

        queue<int> q;

        for (int i = 0; i < roads.size() + 1; i++) {
            if (nodes[i].neighbors.size() == 1) {
                q.push(i);
            }
        }

        long fuel = 0;

        while (q.size() != 0) {

            if (q.front() == 0 || nodes[q.front()].visited == true) {
                q.pop();
                continue;
            }

            struct node* currnode = &nodes[q.front()];

            if (currnode->riders > currnode->cars * seats) {
                currnode->cars += 1;
            } else {
                currnode->cars = ceil(currnode->riders / seats); 
            }

            for (auto it : currnode->neighbors) {
                if (nodes[it].visited == false) {
                    fuel += currnode->cars;
                    nodes[it].cars += currnode->cars;
                    nodes[it].riders += currnode->riders;
                    q.push(it);
                }
            }

            currnode->visited = true;
            cout << q.front() << endl;
            q.pop();

        }


        return fuel;


    }
};
