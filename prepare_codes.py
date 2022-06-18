import argparse
import subprocess
from ast import parse
from email.policy import default
from pathlib import Path
from typing import List

template_code = """
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cassert>
#include <queue>
#include <map>
#include <set>
using namespace std;
using Int = int64_t;
using P = pair<Int, Int>;
const Int INF = 1 << 30;
const Int MOD = (Int)1e9 + 7;
const Int MAX_N = (Int)1e5 + 5;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl;
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << p.first << " " << p.second;
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
        os << v[i] << (i + 1 != v.size() ? " " : "");
    return os;
}

void solve()
{
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
"""


def main(args: argparse.Namespace):
    dir: Path = args.dir
    problems: List[str] = args.problems
    dir.mkdir(parents=True, exist_ok=True)

    for problem in problems:
        problem_path: Path = dir / problem
        problem_path.with_suffix(".cpp").write_text(template_code.lstrip("\n"))

    list_files = [str(file) for file in dir.glob("*.cpp")]
    print(f"Created files: {list_files}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Prepare code for the contest")
    parser.add_argument(
        "--dir", type=Path, default=Path().cwd(), help="Directory to store the codes",
    )
    parser.add_argument(
        "--problems",
        nargs="+",
        default=["a", "b", "c", "d", "e", "f"],
        help="List of problems to prepare",
    )

    args = parser.parse_args()
    main(args)
