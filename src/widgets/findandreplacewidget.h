#ifndef FINDANDREPLACEWIDGET_H
#define FINDANDREPLACEWIDGET_H

#include <QWidget>

#include <QVector>

#include <core/global.h>

class QLineEdit;
class QCheckBox;
class QTimer;

namespace vnotex
{
    class FindAndReplaceWidget : public QWidget
    {
        Q_OBJECT
    public:
        explicit FindAndReplaceWidget(QWidget *p_parent = nullptr);

        void setReplaceEnabled(bool p_enabled);

        void open(const QString &p_text);

        void close();

    signals:
        void findTextChanged(const QString &p_text, FindOptions p_options);

    protected:
        void keyPressEvent(QKeyEvent *p_event) Q_DECL_OVERRIDE;

    private slots:
        void findNext();

        void findPrevious();

        void updateFindOptions();

        void replace();

        void replaceAndFind();

        void replaceAll();

    private:
        void setupUI();

        void setFindOptions(FindOptions p_options);

        QLineEdit *m_findLineEdit = nullptr;

        QLineEdit *m_replaceLineEdit = nullptr;

        QVector<QWidget *> m_replaceRelatedWidgets;

        QCheckBox *m_caseSensitiveCheckBox = nullptr;

        QCheckBox *m_wholeWordOnlyCheckBox = nullptr;

        QCheckBox *m_regularExpressionCheckBox = nullptr;

        QCheckBox *m_incrementalSearchCheckBox = nullptr;

        FindOptions m_options = FindOption::None;

        QTimer *m_findTextTimer = nullptr;
    };
}

#endif // FINDANDREPLACEWIDGET_H
