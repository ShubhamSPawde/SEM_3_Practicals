class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> ans;
        if (n < 4) return ans;

        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && arr[i] == arr[i - 1]) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && arr[j] == arr[j - 1]) continue;

                int a = j + 1;
                int b = n - 1;
                while (a < b) {
                    int sum = arr[i] + arr[j] + arr[a] + arr[b];
                    if (sum == k) {
                        ans.push_back({arr[i], arr[j], arr[a], arr[b]});
                        while (a < b && arr[a] == arr[a + 1]) a++;
                        while (a < b && arr[b] == arr[b - 1]) b--;
                        a++;
                        b--;
                    } else if (sum < k) {
                        a++;
                    } else {
                        b--;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        set <vector<int>> s;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int start = j + 1;
                int end = n - 1;
                while (start < end)
                {
                    int sum = arr[i] + arr[j] + arr[start] + arr[end];
                    if (sum == k)
                    {
                        s.insert({arr[i], arr[j], arr[start], arr[end]});
                        start++;
                        end--;
                    }
                    else if (sum > k)
                    {
                        end--;
                    }
                    else
                    {
                        start++;
                    }
                }
            }
        }
        for (auto i : s)
        {
            ans.push_back(i);
        }
        return ans;
    }
};
