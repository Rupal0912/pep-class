# Subarray Sum Equals K (Print All Subarrays)

## Problem Statement

Given an integer array `arr` and an integer `k`, print all subarrays whose sum equals `k`.

---

## 🔎 Key Idea

We use the **Prefix Sum** technique.

If:

```
prefixSum[j] - prefixSum[i] = k
```

Then:

```
Subarray from (i+1) to j has sum = k
```

Rearranged:

```
prefixSum[j] - k = prefixSum[i]
```

So while traversing the array:
- Maintain current prefix sum
- If `(currentSum - k)` exists before
- Then we found one or more valid subarrays

---

## 💡 Why We Use a Hash Map

We store:

```
unordered_map<int, vector<int>>
```

This maps:

```
prefixSum → list of indices where it occurred
```

We store **all indices** because the same prefix sum can occur multiple times.

---

## ⚙️ Algorithm Steps

1. Initialize:
   - `prefixSum = 0`
   - `mp[0].push_back(-1)` (important for subarrays starting at index 0)

2. Traverse the array:
   - Add current element to `prefixSum`
   - Check if `(prefixSum - k)` exists in map
   - If yes:
     - For each stored index
     - Print subarray from `index + 1` to current index
   - Store current index in `mp[prefixSum]`

---

## 🧠 Code Implementation (C++)

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void printSubarrays(vector<int>& arr, int k) {
    unordered_map<int, vector<int>> mp;
    int prefixSum = 0;

    // Important for subarrays starting from index 0
    mp[0].push_back(-1);

    for(int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        if(mp.find(prefixSum - k) != mp.end()) {
            for(int startIndex : mp[prefixSum - k]) {

                for(int j = startIndex + 1; j <= i; j++) {
                    cout << arr[j] << " ";
                }
                cout << endl;
            }
        }

        mp[prefixSum].push_back(i);
    }
}
```

---

## 📌 Example

Input:

```
arr = [1, 2, 3]
k = 3
```

Output:

```
1 2
3
```

---

## ⏱ Time Complexity

- Traversal: `O(n)`
- Printing: Depends on number of valid subarrays (can be `O(n²)`)

Total complexity depends on output size.

---

## 📦 Space Complexity

```
O(n)
```

For storing prefix sums and indices.

---

## ⚠ Important Notes

- Works with negative numbers.
- Sliding window does NOT work if negatives are present.
- Storing indices is necessary to print subarrays.
- `mp[0].push_back(-1)` handles subarrays starting at index 0.

---

## 🎯 When to Use This Pattern

Use prefix sum when:

- Problem involves subarray sums
- Negative numbers exist
- You need count or actual subarrays
- Efficient lookup of previous sums is required
