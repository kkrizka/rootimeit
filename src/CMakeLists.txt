FIND_PACKAGE(ROOT REQUIRED)
INCLUDE(${ROOT_USE_FILE})

SET(HEADERS LoadBase.h
  LoadVector.h
  LoadArray.h)

SET(SRCS LoadBase.cxx
  LoadVector.cxx
  LoadArray.cxx)

ROOT_GENERATE_DICTIONARY(G__rootimeit ${HEADERS} LINKDEF LinkDef.h)

ADD_LIBRARY(rootimeit SHARED ${SRCS} G__rootimeit.cxx)
TARGET_LINK_LIBRARIES(rootimeit ${ROOT_LIBRARIES})

ADD_EXECUTABLE(rootimeittest main.cxx ${SRCS})
TARGET_LINK_LIBRARIES(rootimeittest ${ROOT_LIBRARIES})
