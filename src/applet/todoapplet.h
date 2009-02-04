/*
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License version 2 as
 *   published by the Free Software Foundation
 *
 *   Copyright (C) 2008 by Javier Goday <jgoday@gmail.com>
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#ifndef TODOAPPLET_H
#define TODOAPPLET_H

// kde ui autogenerated file
#include "ui_todoappletconfig.h"

// Qt headers
#include <QMap>

// Plasma includes
#include <Plasma/PopupApplet>
#include <Plasma/DataEngine>

class QComboBox;
class QGraphicsLinearLayout;
class QGraphicsProxyWidget;
class QModelIndex;
class KCategorizedSortFilterProxyModel;
class KConfigDialog;
class TodoModel;
class TodoView;

class TodoApplet : public Plasma::PopupApplet
{
    Q_OBJECT
public:
    TodoApplet(QObject *parent, const QVariantList &args);
    ~TodoApplet();

    void init();
    QWidget *widget();

public slots:
    void dataUpdated(const QString &name, const Plasma::DataEngine::Data &data);

private slots:
    void slotOpenTodo(const QModelIndex &index);
    void slotAddTodo();

protected slots:
    void configAccepted();

protected:
    void createConfigurationInterface(KConfigDialog *parent);

private:
    void doLayout();

private:
    void updateCategories(const QStringList &categories);
    void updateColors(const QMap <QString, QVariant> &colors);
    void updateTodoList(const QList <QVariant> &todos);

private:
    Plasma::DataEngine    *m_engine;

    QComboBox             *m_types; // todos categories combobox
    QGraphicsProxyWidget  *m_proxyWidget; // proxy widget
    QWidget               *m_widget; // main widget

    KCategorizedSortFilterProxyModel *m_proxyModel;
    TodoModel             *m_model;
    TodoView              *m_view;

    Ui::TodoAppletConfig  m_configUi;
};
#endif
