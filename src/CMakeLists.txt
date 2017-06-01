FIND_PACKAGE(ROOT REQUIRED)
INCLUDE(${ROOT_USE_FILE})

SET(HEADERS
  Test.h
  LoadBase.h
  LoadVector.h
  LoadArray.h
  LoadTClonesArray.h)

SET(SRCS
  Test.cxx
  LoadBase.cxx
  LoadVector.cxx
  LoadArray.cxx
  LoadTClonesArray.cxx)

ROOT_GENERATE_DICTIONARY(G__rootimeit ${HEADERS} LINKDEF LinkDef.h)

ADD_LIBRARY(rootimeit SHARED ${SRCS} G__rootimeit.cxx)
TARGET_LINK_LIBRARIES(rootimeit ${ROOT_LIBRARIES})

ADD_EXECUTABLE(rootimeittest main.cxx)
TARGET_LINK_LIBRARIES(rootimeittest rootimeit ${ROOT_LIBRARIES})
