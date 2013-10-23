# This file must be included for any external usage of cvs_application_base library!
#
# Input  parameter : $$TARGET, $$HOSTBASE_DIR
# Output parameters: $$HOSTBASE_BINDIR, $$OBJECTS_DIR
#

# all projects, which start by including this file, set defined config and QT-config to below values:
#
QT      = core gui xml
CONFIG += link_prl
CONFIG += console                                   # create console log for all our apps

# all our hostBased apps use utils lib

# Using only open part of the project
UTILSDIR = $$HOSTBASE_DIR/../../utils
include($$UTILSDIR/utils.pri)

#message(Utils dir $$UTILSDIR)
#message(Utils bin dir $$UTILS_BINDIR)
#message(Core dir $$COREDIR)
#message(Core bin dir $$COREBINDIR)

# qmake's bug found on mingw-win config:
# hostBase.pri is included here from current dir and it includes utils.pri from its dir.
# So the path to mocinclude.tmp for derived projects (host-*) is created as:
# "./../utils/../../../.obj/$$TARGET_ORIG" that is the same as "./../../../.obj/$$TARGET_ORIG".
# But they're unequal from the generated makefile view point.
#
win32 {
    MOC_DIR = $$ROOT_DIR/.obj/$$TARGET_ORIG/$$BUILD_CFG_NAME  # resolve moc path for mocs to help qmake to unify those paths.
}

HOSTBASE_INCLUDEPATH = \
    $$HOSTBASE_DIR \
    $$HOSTBASE_DIR/generatedParameters \
    $$HOSTBASE_DIR/memoryUsageCalculator \
    $$HOSTBASE_DIR/parametersMapper \
    $$HOSTBASE_DIR/statistics \
    $$HOSTBASE_DIR/layers \
    

INCLUDEPATH += $$HOSTBASE_INCLUDEPATH

HOSTBASE_BINDIR = $$UTILS_BINDIR

contains(TARGET_ORIG, cvs_application_base) {
    !win32-msvc*: DEPENDPATH += $$HOSTBASE_INCLUDEPATH  # msvc sets this automatically by deps from includes for this project
} else {
    !win32-msvc*: DEPENDPATH += $$HOSTBASE_INCLUDEPATH  # msvc sets this automatically by deps from includes for other projects! :(

    # The "HOSTBASE_INTDIR" path should be known for other projects that use "cvs_application_base"!
    win32 {
        HOSTBASE_INTDIR = $$ROOT_DIR/.obj/cvs_application_base/$$BUILD_CFG_NAME
    } else {
        HOSTBASE_INTDIR = $$ROOT_DIR/.obj/cvs_application_base
    }
    INCLUDEPATH += $$HOSTBASE_INTDIR                # add autogenerated ui* headers of cvs_application_base into include path for the current project

    HOSTBASE_TARGET_NAME = cvs_application_base
    HOSTBASE_TARGET_NAME = $$join(HOSTBASE_TARGET_NAME,,,$$BUILD_CFG_SFX)

    LIBS = -L$$HOSTBASE_BINDIR -l$$HOSTBASE_TARGET_NAME  $$LIBS

    win32-msvc* {
        HOSTBASE_TARGET_NAME = $$join(HOSTBASE_TARGET_NAME,,,.lib)
        PRE_TARGETDEPS      += $$HOSTBASE_BINDIR/$$HOSTBASE_TARGET_NAME
    } else {
        HOSTBASE_TARGET_NAME = $$join(HOSTBASE_TARGET_NAME,,lib,.a)
        PRE_TARGETDEPS      += $$HOSTBASE_BINDIR/$$HOSTBASE_TARGET_NAME
    }
}

!staticlib {
    #
    # resources for each of our building app. Unfortunately it doesn't work by been added into a lib :(
    #
    RESOURCES += $$HOSTBASE_DIR/../../resources/main.qrc

    contains(DEFINES, WITH_OPENCL) {
        OPENCL_QRC_DIR = $$HOSTBASE_DIR/../../resources/opencl

        RESOURCES += $$OPENCL_QRC_DIR/opencl.qrc

        #RESOURCES.CONFIG += no_check_exist         # unfortunately it doesn't work :(

        !exists($$OPENCL_QRC_DIR/ocl.zip) {         # the code that should work only once...
            win32 {
                # back slashes in the path are not allowed in the command, so we use the relative direct path
                system($$QMAKE_COPY ..\\..\\..\\..\\resources\\opencl\\ocl_dummy.zip ..\\..\\..\\..\\resources\\opencl\\ocl.zip >nul)
            } else {
                system($$QMAKE_COPY $$OPENCL_QRC_DIR/ocl_dummy.zip $$OPENCL_QRC_DIR/ocl.zip >nul)
            }
        }
    }
}