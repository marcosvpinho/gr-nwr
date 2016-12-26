/* -*- c++ -*- */
/*
 * Copyright 2004,2011,2012 Free Software Foundation, Inc.
 * Copyright (C) 2016  Andy Walls <awalls.cx18@gmail.com>
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_NWR_CLOCK_RECOVERY_MM_FF_H
#define	INCLUDED_NWR_CLOCK_RECOVERY_MM_FF_H

#include <nwr/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace nwr {
    
    /*!
     * \brief Mueller and Müller (M&M) based clock recovery block with float input, float output.
     * \ingroup synchronizers_blk
     *
     * \details
     * This implements the Mueller and Müller (M&M) discrete-time
     * error-tracking synchronizer.
     *
     * See "Digital Communication Receivers: Synchronization, Channel
     * Estimation and Signal Processing" by Heinrich Meyr, Marc
     * Moeneclaey, & Stefan Fechtel.  ISBN 0-471-50275-8.
     */
    class NWR_API clock_recovery_mm_ff : virtual public block
    {
    public:
      // gr::nwr::clock_recovery_mm_ff::sptr
      typedef boost::shared_ptr<clock_recovery_mm_ff> sptr;

      /*!
       * Make a M&M clock recovery block.
       *
       * \param omega User specified nominal clock period in samples per symbol
       * \param gain_omega Integral gain of the PI loop filter
       * \param mu Initial estimate of the instantaneous clock period (ignored)
       * \param gain_mu Proportional gain of the PI loop filter
       * \param omega_relative_limit Maximum relative deviation of the average clock period estimate from the user specified nominal clock period
       */
      static sptr make(float omega, float gain_omega,
		       float mu, float gain_mu,
		       float omega_relative_limit);
      
      virtual float mu() const = 0;
      virtual float omega() const = 0;
      virtual float gain_mu() const = 0;
      virtual float gain_omega() const = 0;

      virtual void set_verbose(bool verbose) = 0;
      virtual void set_gain_mu (float gain_mu) = 0;
      virtual void set_gain_omega (float gain_omega) = 0;
      virtual void set_mu (float mu) = 0;
      virtual void set_omega (float omega) = 0;
    };

  } /* namespace nwr */
} /* namespace gr */

#endif /* INCLUDED_NWR_CLOCK_RECOVERY_MM_FF_H */
