
    int smallest = arr[0] + k;
    int largest = arr[n - 1] - k;

    for (int i = 1; i < n; i++)
    {
        int minH = min(smallest, arr[i] - k);
        int maxH = max(largest, arr[i - 1] + k);

        if (minH < 0)
            continue; // skip invalid case

        ans = min(ans, maxH - minH);
    }

    return ans;
}
