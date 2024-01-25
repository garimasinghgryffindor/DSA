// Problem statement
// Alice is a huge fan of traveling these days, so she wants to travel to reach her destination.

// There are 'N' cities numbered from '0' to 'N - 1' in Alice's country. All the cities are associated with a specific value. More specifically, the city 'i' has a value equal to 'A[i]'.

// Currently, Alice is in her house, which is located in city '0'. She wants to reach her destination in the city 'N - 1'.

// In her country, there are special flights for each pair of cities with different travel costs to move from one city to another. More specifically, the flight going from city 'a' to city 'b' will have a traveling cost equal to the sum of all 'A[i]', where, 'a' < 'i' < 'b' if 'a' is less than 'b' and 'b' < 'i' < 'a' otherwise.

// Alice has 'K' rupees initially. She wants to use less number of flights to reach her destination as she likes to save time wasted in changing flights.

// Your task is to find the minimum number of flights she must use to reach city 'N - 1' within 'K' rupees and return it.

// Example:
// N = 4
// K = 3
// A = [1, 2, 5, 1]
// Initially, Alice is in city '0'.
// She will use the flight to move to city '2' from '0'. It will cost 'A[1]' = '2' rupees.
// Then she will use the flight to move to city '3' from '2'. It will cost '0' rupees.
// So she reached her destination with a total cost of '2' rupees by using '2' flights.
// It can be proved that she can not reach her destination by using less than '2' flights within '3' rupees.
// So the answer for this case is '2'.

  
int minimumFlights(int n, int k, vector<int> a) {
    // Write your code here.
    vector<int> actualCosts;
    for(int i = 1; i < n-1; i++) {
        actualCosts.push_back(a[i]);
    }

    sort(actualCosts.begin(), actualCosts.end());

    int l = 0, r = n-2;
    // costs added equals cost of actual flights
    // costs cannot be accomodated are flights changed
    while(l < r && k-actualCosts[l] >= 0) {
        k-= actualCosts[l++];
    }

    return r-l+1;
}
