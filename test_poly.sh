#!/bin/sh

set -v

./Polynomial << EOF
4
3 -2 8 -9 7
4
3 -2 8 -9 7
-3
2
-2
2
2
-2 
EOF

./Polynomial << EOF
2
3 5 -3
4
1 0 -8 0 2
8
0
0
12
2
7
EOF

./Polynomial << EOF
12
4 -4 2 -10 3 -12 0 0 0 3 -6 10 -2
4
2 8 -3 2
8
2
-3
-2
3
4
EOF