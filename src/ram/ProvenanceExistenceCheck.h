/*
 * Souffle - A Datalog Compiler
 * Copyright (c) 2013, 2014, Oracle and/or its affiliates. All rights reserved
 * Licensed under the Universal Permissive License v 1.0 as shown at:
 * - https://opensource.org/licenses/UPL
 * - <souffle root>/licenses/SOUFFLE-UPL.txt
 */

/************************************************************************
 *
 * @file ProvenanceExistenceCheck.h
 *
 * Defines a class for evaluating conditions in the Relational Algebra
 * Machine.
 *
 ***********************************************************************/

#pragma once

#include "ram/AbstractExistenceCheck.h"
#include "ram/Expression.h"
#include "ram/Relation.h"
#include "souffle/utility/MiscUtil.h"
#include <memory>
#include <sstream>
#include <utility>
#include <vector>

namespace souffle::ram {

/**
 * @class ProvenanceExistenceCheck
 * @brief Provenance Existence check for a relation
 */
class ProvenanceExistenceCheck : public AbstractExistenceCheck {
public:
    ProvenanceExistenceCheck(Own<RelationReference> relRef, VecOwn<Expression> vals)
            : AbstractExistenceCheck(std::move(relRef), std::move(vals)) {}

    ProvenanceExistenceCheck* clone() const override {
        VecOwn<Expression> newValues;
        for (auto& cur : values) {
            newValues.emplace_back(cur->clone());
        }
        return new ProvenanceExistenceCheck(souffle::clone(relationRef), std::move(newValues));
    }

protected:
    void print(std::ostream& os) const override {
        os << "prov";
        AbstractExistenceCheck::print(os);
    }
};

}  // namespace souffle::ram
