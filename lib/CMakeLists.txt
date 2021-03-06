#
# Copyright (C) 2016  Andy Walls <awalls.cx18@gmail.com>
#
# This file was automatically generated by gr_modtool from GNU Radio
#
# This file was automatically generated from a template incorporating
# data input by Andy Walls and subsequently hand edited by Andy Walls.
# See http://www.gnu.org/licenses/gpl-faq.en.html#GPLOutput .
#

########################################################################
# Setup library
########################################################################
include(GrPlatform) #define LIB_SUFFIX

include_directories(${Boost_INCLUDE_DIR} ${UHD_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS} ${UHD_LIBRARY_DIRS})

list(APPEND nwr_sources
    clock_tracking_loop.cc
    lms_da_equalizer_ff_impl.cc
    burst_detect_and_tag_impl.cc
    correction_estimator_ff_impl.cc
    multiply_by_tag_value_ff_impl.cc
    add_tag_value_ff_impl.cc
    clock_recovery_mm_ff_impl.cc
    clock_recovery_mm_cc_impl.cc
    interpolating_resampler.cc
    mmse_interp_differentiator_ff.cc
    mmse_interp_differentiator_cc.cc
    pll_refout_cc_impl.cc
    same_burst_decoder_impl.cc
    symbol_sync_ff_impl.cc
    symbol_sync_cc_impl.cc
    timing_error_detector.cc
)

set(nwr_sources "${nwr_sources}" PARENT_SCOPE)
if(NOT nwr_sources)
	MESSAGE(STATUS "No C++ sources... skipping lib/")
	return()
endif(NOT nwr_sources)

add_library(gnuradio-nwr SHARED ${nwr_sources})
target_link_libraries(gnuradio-nwr ${Boost_LIBRARIES} ${UHD_LIBRARIES} ${GNURADIO_ALL_LIBRARIES})
set_target_properties(gnuradio-nwr PROPERTIES DEFINE_SYMBOL "gnuradio_nwr_EXPORTS")

if(APPLE)
    set_target_properties(gnuradio-nwr PROPERTIES
        INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib"
    )
endif(APPLE)

########################################################################
# Install built library files
########################################################################
include(GrMiscUtils)
GR_LIBRARY_FOO(gnuradio-nwr RUNTIME_COMPONENT "nwr_runtime" DEVEL_COMPONENT "nwr_devel")

########################################################################
# Build and register unit test
########################################################################
include(GrTest)

include_directories(${CPPUNIT_INCLUDE_DIRS})

list(APPEND test_nwr_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/test_nwr.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/qa_nwr.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/qa_mmse_interp_differentiator_ff.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/qa_mmse_interp_differentiator_cc.cc
)

add_executable(test-nwr ${test_nwr_sources})

target_link_libraries(
  test-nwr
  ${GNURADIO_RUNTIME_LIBRARIES}
  ${Boost_LIBRARIES}
  ${UHD_LIBRARIES}
  ${CPPUNIT_LIBRARIES}
  gnuradio-nwr
)

GR_ADD_TEST(test_nwr test-nwr)

########################################################################
# Print summary
########################################################################
message(STATUS "Using install prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Building for version: ${VERSION} / ${LIBVER}")

