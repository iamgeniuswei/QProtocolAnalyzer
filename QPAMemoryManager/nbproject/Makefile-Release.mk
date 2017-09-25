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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/wmem_allocator_block.o \
	${OBJECTDIR}/src/wmem_allocator_block_fast.o \
	${OBJECTDIR}/src/wmem_allocator_simple.o \
	${OBJECTDIR}/src/wmem_allocator_strict.o \
	${OBJECTDIR}/src/wmem_array.o \
	${OBJECTDIR}/src/wmem_core.o \
	${OBJECTDIR}/src/wmem_interval_tree.o \
	${OBJECTDIR}/src/wmem_list.o \
	${OBJECTDIR}/src/wmem_map.o \
	${OBJECTDIR}/src/wmem_miscutl.o \
	${OBJECTDIR}/src/wmem_scopes.o \
	${OBJECTDIR}/src/wmem_stack.o \
	${OBJECTDIR}/src/wmem_strbuf.o \
	${OBJECTDIR}/src/wmem_strutl.o \
	${OBJECTDIR}/src/wmem_tree.o \
	${OBJECTDIR}/src/wmem_user_cb.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAMemoryManager.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAMemoryManager.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libQPAMemoryManager.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/wmem_allocator_block.o: src/wmem_allocator_block.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wmem_allocator_block.o src/wmem_allocator_block.cpp

${OBJECTDIR}/src/wmem_allocator_block_fast.o: src/wmem_allocator_block_fast.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wmem_allocator_block_fast.o src/wmem_allocator_block_fast.cpp

${OBJECTDIR}/src/wmem_allocator_simple.o: src/wmem_allocator_simple.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wmem_allocator_simple.o src/wmem_allocator_simple.cpp

${OBJECTDIR}/src/wmem_allocator_strict.o: src/wmem_allocator_strict.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wmem_allocator_strict.o src/wmem_allocator_strict.cpp

${OBJECTDIR}/src/wmem_array.o: src/wmem_array.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wmem_array.o src/wmem_array.cpp

${OBJECTDIR}/src/wmem_core.o: src/wmem_core.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wmem_core.o src/wmem_core.cpp

${OBJECTDIR}/src/wmem_interval_tree.o: src/wmem_interval_tree.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wmem_interval_tree.o src/wmem_interval_tree.cpp

${OBJECTDIR}/src/wmem_list.o: src/wmem_list.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wmem_list.o src/wmem_list.cpp

${OBJECTDIR}/src/wmem_map.o: src/wmem_map.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wmem_map.o src/wmem_map.cpp

${OBJECTDIR}/src/wmem_miscutl.o: src/wmem_miscutl.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wmem_miscutl.o src/wmem_miscutl.cpp

${OBJECTDIR}/src/wmem_scopes.o: src/wmem_scopes.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wmem_scopes.o src/wmem_scopes.cpp

${OBJECTDIR}/src/wmem_stack.o: src/wmem_stack.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wmem_stack.o src/wmem_stack.cpp

${OBJECTDIR}/src/wmem_strbuf.o: src/wmem_strbuf.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wmem_strbuf.o src/wmem_strbuf.cpp

${OBJECTDIR}/src/wmem_strutl.o: src/wmem_strutl.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wmem_strutl.o src/wmem_strutl.cpp

${OBJECTDIR}/src/wmem_tree.o: src/wmem_tree.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wmem_tree.o src/wmem_tree.cpp

${OBJECTDIR}/src/wmem_user_cb.o: src/wmem_user_cb.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/wmem_user_cb.o src/wmem_user_cb.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
