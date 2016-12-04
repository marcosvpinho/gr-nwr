/* -*- c++ -*- */
/*
 * Copyright (C) 2016  Andy Walls <awalls.cx18@gmail.com>
 *
 * This file was automatically generated by gr_modtool from GNU Radio
 *
 * This file was automatically generated from a template incorporating
 * data input by Andy Walls and subsequently hand edited by Andy Walls.
 * See http://www.gnu.org/licenses/gpl-faq.en.html#GPLOutput .
 */

#define NWR_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "nwr_swig_doc.i"

%{
#include "nwr/lms_da_equalizer_ff.h"
#include "nwr/burst_detect_and_tag.h"
%}


%include "nwr/lms_da_equalizer_ff.h"
GR_SWIG_BLOCK_MAGIC2(nwr, lms_da_equalizer_ff);
%include "nwr/burst_detect_and_tag.h"
GR_SWIG_BLOCK_MAGIC2(nwr, burst_detect_and_tag);
