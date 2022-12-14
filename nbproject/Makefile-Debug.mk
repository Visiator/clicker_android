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
	${OBJECTDIR}/_ext/67dd150d/font.o \
	${OBJECTDIR}/_ext/67dd150d/gui.o \
	${OBJECTDIR}/_ext/67dd150d/tools.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-pthread
CXXFLAGS=-pthread

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/clicker_android

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/clicker_android: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/clicker_android ${OBJECTFILES} ${LDLIBSOPTIONS} -lX11 -lXtst

${OBJECTDIR}/_ext/67dd150d/font.o: /home/smorodin/NetBeansProjects/clicker_android/font.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/67dd150d
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/67dd150d/font.o /home/smorodin/NetBeansProjects/clicker_android/font.cpp

${OBJECTDIR}/_ext/67dd150d/gui.o: /home/smorodin/NetBeansProjects/clicker_android/gui.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/67dd150d
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/67dd150d/gui.o /home/smorodin/NetBeansProjects/clicker_android/gui.cpp

${OBJECTDIR}/_ext/67dd150d/tools.o: /home/smorodin/NetBeansProjects/clicker_android/tools.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/67dd150d
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/67dd150d/tools.o /home/smorodin/NetBeansProjects/clicker_android/tools.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

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
