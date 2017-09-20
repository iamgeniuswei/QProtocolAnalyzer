#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Wl,-rpath,'../QPAFileHelper/dist/Debug/GNU-Linux' -L../QPAFileHelper/dist/Debug/GNU-Linux -lQPAFileHelper -Wl,-rpath,'../QPASkeleton/dist/Debug/GNU-Linux' -L../QPASkeleton/dist/Debug/GNU-Linux -lQPASkeleton -Wl,-rpath,'../QPAUtility/dist/Debug/GNU-Linux' -L../QPAUtility/dist/Debug/GNU-Linux -lQPAUtility

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qprotocolanalyzer
	${CP} ../QPAFileHelper/dist/Debug/GNU-Linux/libQPAFileHelper.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../QPASkeleton/dist/Debug/GNU-Linux/libQPASkeleton.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${CP} ../QPAUtility/dist/Debug/GNU-Linux/libQPAUtility.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qprotocolanalyzer: ../QPAFileHelper/dist/Debug/GNU-Linux/libQPAFileHelper.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qprotocolanalyzer: ../QPASkeleton/dist/Debug/GNU-Linux/libQPASkeleton.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qprotocolanalyzer: ../QPAUtility/dist/Debug/GNU-Linux/libQPAUtility.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qprotocolanalyzer: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qprotocolanalyzer ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../QPAFileHelper/src -I../QPASkeleton/src -I../QPAUtility/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:
	cd ../QPAFileHelper && ${MAKE}  -f Makefile CONF=Debug
	cd ../QPASkeleton && ${MAKE}  -f Makefile CONF=Debug
	cd ../QPAUtility && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAFileHelper.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPASkeleton.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAUtility.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qprotocolanalyzer

# Subprojects
.clean-subprojects:
	cd ../QPAFileHelper && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../QPASkeleton && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../QPAUtility && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
