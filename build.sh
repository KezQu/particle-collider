
#!/usr/bin/env bash
set -euo pipefail

if [ "${1-}" = "clean" ]; then
	echo "Cleaning build directory..."
	rm -rf build
fi

cmake -S . -B build && cd build && make -j16
cd -
