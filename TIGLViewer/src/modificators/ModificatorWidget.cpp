/*
 * Copyright (C) 2018 CFS Engineering
 *
 * Created: 2018 Malo Drougard <malo.drougard@protonmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ModificatorWidget.h"
#include "CTiglLogging.h"
#include <cmath>

ModificatorWidget::ModificatorWidget(QWidget* parent)
    : QWidget(parent)
{
    precision = 3; // by default the precision is 10^-3
}

bool ModificatorWidget::apply()
{
    LOG(WARNING) << "ModificatorWidget: apply function should be overwrite in "
                    "children classes";
    return false;
}

void ModificatorWidget::reset()
{
    LOG(WARNING) << "ModificatorWidget: reset function should be overwrite in "
                    "children classes";
}

bool ModificatorWidget::isApprox(double a, double b)
{
    // so if the spin box is set with precision "precision", only the real change
    // are detected and not the rounding
    double delta = pow(10, -precision) / 2.0;
    return (fabs(a - b) <= delta);
}
