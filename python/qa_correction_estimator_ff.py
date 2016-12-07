#!/usr/bin/env python
# -*- coding: utf-8 -*-
# 
# Copyright (C) 2016  Andy Walls <awalls.cx18@gmail.com>
#
# This file was automatically generated by gr_modtool from GNU Radio
#
# This file was automatically generated from a template incorporating
# data input by Andy Walls.
# See http://www.gnu.org/licenses/gpl-faq.en.html#GPLOutput .
#

from gnuradio import gr, gr_unittest
from gnuradio import blocks
import nwr_swig as nwr

class qa_correction_estimator_ff (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block ()

    def tearDown (self):
        self.tb = None

    def test_001_t (self):
        # set up fg
        self.tb.run ()
        # check data


if __name__ == '__main__':
    gr_unittest.run(qa_correction_estimator_ff, "qa_correction_estimator_ff.xml")
