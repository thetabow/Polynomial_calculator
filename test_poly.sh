#!/bin/sh

set -v

./Polynomial << EOF
2
3 -2 1
2
2 2 2 
EOF
./Polynomial << EOF
4
3 -2 8 -9 7
1
1 -1
EOF

./Polynomial << EOF
13
4 8 -9 22 6 8 -3 9 6 2 -44 5 8 12
3
4 8 6 2
EOF
