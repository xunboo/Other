/*
You have a set of cars and parking lots.

You know the distances from each car to each parking lot and the parking lot capacities.

How would you make sure each car gets to a parking lot with a vacancy so that all cars travel the least amount of total distance possible?

A small data set example might be:

distance_car1_to_lot1 = 1
distance_car1_to_lot2 = 10
distance_car2_to_lot1 = 2
distance_car2_to_lot2 = 100
lot1_capacity = 1
lot2_capacity = 1

You can see here that if you were to take car1 and put it into lot1 and car2 into lot2, the distance traveled of all cars would be 101.

Rather than doing that, taking car1 to lot2 and car2 to lot1 would result in a total travel distance of 12. Which would be the correct answer in this small data set.

How might you solve this, assuming there could a wide number of cars, parking lots and varying distances than listed above.  

*/
vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        do {
            result.emplace_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return result;
    }

    vector<vector<int>> permute2(int total) {
        vector<int> nums;
        for(int i =0;i<total;i++ )
            nums.emplace_back(i);
        vector<vector<int> > result;
        do {
            result.emplace_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return result;
    }


//vector<vector<int> > cost{{1, 3, 5}, {4, 2, 1}, {1, 5, 3}};
vector<vector<int> > cost{{1, 10, 1, 10}, {2, 100, 2, 100}, {1, 10, 1, 10}, {2, 100, 2, 100}};
    vector<vector<int> > ret = permute2(cost.size());

    int min=-1;
    int carnum=1;
    for(int i = 0; i<ret.size();i++){
        int dist = 0;
        int j;
        for(j = 0; j<ret[0].size();j++){
            if(j>=cost.size() || ret[i][j] >= cost[0].size()){
                throw 1;
            }
            dist += cost[j][ret[i][j]];
        }

        if(min==-1 || min>dist){
            printf("update min to %d, %d - %d\n", dist,i,j-1);
            min=dist;

            /*carnum--;
            if(carnum==0)
               break;*/
        }
    }



    printf("end %d\n", min);

    
}
