# Exchange platform
C++ Exchange_platform

## How to run
```bash
cmake . -G "Unix Makefiles"
make
./Exchange_platform
```

## Baby step
```bash
# To pull 
git pull https://github.com/wwyzhao/wo_exchange_platform.git

# To commit 
git commit -m "commit message"

# To push
git push
```

## How to write code
If you add a new cpp, please add them to CMakeLists:
```bash
add_library(Exchange_platformLib STATIC
        platform/wo_exchange
        platform/Admins
        XXX/XXX <--- add new cpp to here!!!!
)
```
