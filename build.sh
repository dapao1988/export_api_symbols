#! /bin/bash

current_path=$(pwd)
#install_prefix="output"
script_dir=`dirname $(realpath $0)`
config_dir=`realpath ${script_dir}/../platform`

BUILD_TARGET=
MODULE_NAME=

function do_host_build() {
    cd ${current_path}
    #rm -rf build
    mkdir -p build
    cd build
    cmake .. -DCMAKE_INSTALL_PREFIX=. -DCMAKE_VERBOSE_MAKEFILE=ON -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=YES -DEXPORT_SYMBOL_DEFAULT=ON
    make -j8 && make test
    make install
}

show_help() {
    echo "Usage: ./build.sh --target=[host|android] [--module=your_partial_build_module_name]"
    echo "--target=<CONFIG>   Target build for. List below:"
    echo "--module=<PATH>     Module path which need to compile."
    echo ""
}

for conf_opt
do
    case ${conf_opt} in
        *=?*) conf_optarg=$(expr "X${conf_opt}" : '[^=]*=\(.*\)') ;;
        *) conf_optarg= ;;
    esac

    case ${conf_opt} in
        --target=*)
            BUILD_TARGET=${conf_optarg}
            ;;
        --module=*)
            MODULE_NAME=${conf_optarg}
            ;;
        *)
        show_help
    esac
done

if [ "${BUILD_TARGET}" = "" ]; then
    echo "Not set build platform, use default linux_x86 instead!!!"
    BUILD_TARGET="host"
    show_help
    echo "Need to set the build target (--target=)."
    echo "Rerun with option \"--help\" to get the whole options."
    echo ""
fi

if [ ${BUILD_TARGET} = "host" -o ${BUILD_TARGET} = "linux_x86" ]; then
    BUILD_TARGET=linux_x86
    do_host_build
fi
BUILD_CONF=${config_dir}/config_${BUILD_TARGET}.ini

if [ "${MODULE_NAME}" = "" ]; then
    MODULE_NAME=`realpath ${PWD}`
#    prepare
else
    MODULE_NAME=`realpath ${MODULE_NAME}`
fi
