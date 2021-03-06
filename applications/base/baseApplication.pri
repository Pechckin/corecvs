# This file must be included for any external usage of cvs_application_base library!
#
# Input  parameter : $$TARGET, $$HOSTBASE_DIR, $$ROOT_DIR
# Output parameters: $$HOSTBASE_BINDIR
#

# all projects, which start by including this file, set defined config and QT-config to below values:
#
QT      = core gui xml
CONFIG += link_prl
CONFIG += console                                   # create console log for all our apps

# All our hostBased apps use utils.lib
#
include($$ROOT_DIR/utils/utils.pri)                        # it uses TARGET, ROOT_DIR and detects UTILS_BINDIR, OBJECTS_DIR, DESTDIR, ...!

#message(Utils dir $$UTILSDIR)
#message(Utils bin dir $$UTILS_BINDIR)
#message(Core dir $$COREDIR)
#message(Core bin dir $$COREBINDIR)

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

    # The "HOSTBASE_INTDIR" path should be known for other projects that use this pri file!
    #
    HOSTBASE_INTDIR = $$ROOT_DIR/.obj/cvs_application_base$$BUILD_CFG_NAME

    INCLUDEPATH += $$HOSTBASE_INTDIR                # add autogenerated ui* headers of cvs_application_base into include path for the current project

    HOSTBASE_TARGET_NAME = cvs_application_base
    HOSTBASE_TARGET_NAME = $$join(HOSTBASE_TARGET_NAME,,,$$BUILD_CFG_SFX)

    LIBS = -L$$HOSTBASE_BINDIR -l$$HOSTBASE_TARGET_NAME $$LIBS

    win32-msvc* {
        HOSTBASE_TARGET_NAME = $$join(HOSTBASE_TARGET_NAME,,,.lib)
    } else {
        HOSTBASE_TARGET_NAME = $$join(HOSTBASE_TARGET_NAME,,lib,.a)
    }
    PRE_TARGETDEPS += $$HOSTBASE_BINDIR/$$HOSTBASE_TARGET_NAME
}
