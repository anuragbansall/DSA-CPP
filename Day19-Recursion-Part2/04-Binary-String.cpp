#include <iostream>
using namespace std;

void binaryString(int n, string ans);

int main(void)
{
    // Print all binary strings of length n with no consecutive 1's
    int n;
    cout << "Enter the length of binary string: ";
    cin >> n;

    binaryString(n, "");

    return 0;
}

void binaryString(int n, string ans)
{
    if (n == 0)
    {
        cout << ans << endl;
        return;
    }

    // Add 0 to the answer string
    binaryString(n - 1, ans + "0");
    // Add 1 to the answer string but only if it doesn't form a consecutive 1
    if (ans.length() == 0 || ans[ans.length() - 1] != '1')
    {
        binaryString(n - 1, ans + "1");
    }
}