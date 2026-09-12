#!/bin/bash

echo ""
echo "======================================"
echo "   DSA Multi-Language Lab"
echo "======================================"
echo ""

echo "Node.js:"
node --version

echo ""
echo "npm:"
npm --version

echo ""
echo "Python:"
python --version

echo ""
echo "pip:"
pip --version

echo ""
echo "G++:"
g++ --version | head -n 1

echo ""
echo "GDB:"
gdb --version | head -n 1

echo ""
echo "Java:"
java --version 2>&1 | head -n 1

echo ""
echo "Java Compiler:"
javac --version

echo ""
echo "Git:"
git --version

echo ""
echo "======================================"
echo "   Environment Ready!"
echo "======================================"
echo ""
