/* -*- c++ -*- */
/*
 * Copyright (C) 2016  Andy Walls <awalls.cx18@gmail.com>
 *
 * This file was automatically generated by gr_modtool from GNU Radio
 *
 * This file was automatically generated from a template incorporating
 * data input by Andy Walls and later hand edited by Andy Walls.
 * See http://www.gnu.org/licenses/gpl-faq.en.html#GPLOutput .
 */

#ifndef INCLUDED_NWR_CORRECTION_ESTIMATOR_FF_H
#define INCLUDED_NWR_CORRECTION_ESTIMATOR_FF_H

#include <nwr/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace nwr {

    /*!
     * \brief (Simple) Correction Estimator (float -> float)
     * \ingroup nwr
     *
     * \details
     * This block simplistically estimates offset and scaling corrections
     * for a burst of samples from the first N samples of a burst,
     * expected to be a preamble, and tags the beginning of the burst with
     * the estimated corrections.  It also tags the end of the burst to
     * indicate the end of corrections (offset of 0.0 and scale of 1.0 or
     * optionally 0.0).
     */
    class NWR_API correction_estimator_ff : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<correction_estimator_ff> sptr;

      /*!
       * \brief Make a simple correction estimator  (float input/float output)
       *
       * \param inspection_length Number of samples to use for the estimates
       * \param inspection_offset Number of samples to skip before inspection
       * \param peak_ref          Expected peak level
       * \param trough_ref        Expected trough level
       * \param offset_corr_key   Tag name to use for the offset correction
       * \param scale_corr_key    Tag name to use for the scaling correction
       * \param scale_eob_zero    Set scaling correction to 0.0 vs 1.0 at end
       * \param timing_win_start  Relative sample when timing est process starts
       * \param timing_win_end    Relative sample when timing est process ends
       * \param time_est_key      Tag name to use for the symbol timing estimate
       * \param clock_est_key     Tag name to use for the symbol clock estimate
       * \param sob_key           Tag name that indicates the start of a burst
       * \param eob_key           Tag name that indicates the end of a burst
       */
      static sptr make(int inspection_length,
                       int inspection_offset = 0,
                       float peak_ref = 1.0f,
                       float trough_ref = -1.0f,
                       const std::string &offset_corr_key = "offset_corr",
                       const std::string &scale_corr_key = "scale_corr",
                       bool scale_eob_zero = false,
                       int timing_win_start = -1,
                       int timing_win_end = -1,
                       const std::string &time_est_key = "time_est",
                       const std::string &clock_est_key = "clock_est",
                       const std::string &sob_key = "rx_sob",
                       const std::string &eob_key = "rx_eob");
    };

  } // namespace nwr
} // namespace gr

#endif /* INCLUDED_NWR_CORRECTION_ESTIMATOR_FF_H */

