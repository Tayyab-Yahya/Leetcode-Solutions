class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas = 0, totCost = 0;

        for(int val : gas){
            totGas += val;
        }
        for(int val : cost){
            totCost += val;
        }

        if(totGas < totCost){
            return -1;
        }

        int currGas = 0, start = 0;

        // Unique solution exists
        for(int i=0; i<gas.size(); i++){
            currGas += gas[i] - cost[i];
            if(currGas < 0){
                currGas = 0;
                start = i+1;
            }
        }

        return start;
    }
};