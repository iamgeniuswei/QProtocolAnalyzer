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
	${OBJECTDIR}/src/QPAMetaInfo.o \
	${OBJECTDIR}/src/QPAPacketReader.o


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
LDLIBSOPTIONS=-Wl,-rpath,'../QPAFileHelper/dist/Debug/GNU-Linux' -L../QPAFileHelper/dist/Debug/GNU-Linux -lQPAFileHelper -Wl,-rpath,'../QPAUtility/dist/Debug/GNU-Linux' -L../QPAUtility/dist/Debug/GNU-Linux -lQPAUtility -Wl,-rpath,'../QPADissector/dist/Debug/GNU-Linux' -L../QPADissector/dist/Debug/GNU-Linux -lQPADissector

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPASkeleton.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPASkeleton.${CND_DLIB_EXT}: ../QPAFileHelper/dist/Debug/GNU-Linux/libQPAFileHelper.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPASkeleton.${CND_DLIB_EXT}: ../QPAUtility/dist/Debug/GNU-Linux/libQPAUtility.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPASkeleton.${CND_DLIB_EXT}: ../QPADissector/dist/Debug/GNU-Linux/libQPADissector.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPASkeleton.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPASkeleton.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/QPAMetaInfo.o: src/QPAMetaInfo.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../QPAFileHelper/src -I../QPAUtility/src -I../QPADissector/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAMetaInfo.o src/QPAMetaInfo.cpp

${OBJECTDIR}/src/QPAPacketReader.o: src/QPAPacketReader.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../QPAFileHelper/src -I../QPAUtility/src -I../QPADissector/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/QPAPacketReader.o src/QPAPacketReader.cpp

# Subprojects
.build-subprojects:
	cd ../QPAFileHelper && ${MAKE}  -f Makefile CONF=Debug
	cd ../QPAUtility && ${MAKE}  -f Makefile CONF=Debug
	cd ../QPADissector && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAFileHelper.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAUtility.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPADissector.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPASkeleton.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../QPAFileHelper && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../QPAUtility && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../QPADissector && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
