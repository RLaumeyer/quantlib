
/*
 Copyright (C) 2000, 2001, 2002 Sadruddin Rejeb

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software developed by the QuantLib Group; you can
 redistribute it and/or modify it under the terms of the QuantLib License;
 either version 1.0, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 QuantLib License for more details.

 You should have received a copy of the QuantLib License along with this
 program; if not, please email ferdinando@ametrano.net

 The QuantLib License is also available at http://quantlib.org/license.html
 The members of the QuantLib Group are listed in the QuantLib License
*/
/*! \file onefactoroperator.hpp
    \brief general differential operator for one-factor interest rate models

    \fullpath
    ql/FiniteDifferences/%onefactoroperator.hpp
*/

// $Id$

#ifndef quantlib_finite_differences_one_factor_operator_h
#define quantlib_finite_differences_one_factor_operator_h

#include <ql/FiniteDifferences/tridiagonaloperator.hpp>
#include <ql/InterestRateModelling/shortrateprocess.hpp>

namespace QuantLib {

    namespace FiniteDifferences {

        //! Interest-rate single factor model differential operator
        class OneFactorOperator : public TridiagonalOperator {
          public:
            OneFactorOperator() {}
            OneFactorOperator(const Array& grid,
                const Handle<ShortRateProcess>& process);
            virtual ~OneFactorOperator() {}

            class SpecificTimeSetter : public TridiagonalOperator::TimeSetter{
              public:
                SpecificTimeSetter(double x0, double dx,
                    const Handle<ShortRateProcess>& process);
                virtual ~SpecificTimeSetter() {}
                virtual void setTime(Time t, TridiagonalOperator& L) const;
              private:
                double x0_;
                double dx_;
                const Handle<ShortRateProcess>& process_;
            };
        };

    }

}


#endif
