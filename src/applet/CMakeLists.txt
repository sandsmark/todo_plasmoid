project(TODOAPPLET)

set(todoapplet_SRCS
    todoapplet.cpp
    todomodel.cpp
    todomodelcategorydelegate.cpp
    todoview.cpp
    todoitemdelegate.cpp
    korganizerutil.cpp
)

qt4_add_dbus_interface(todoapplet_SRCS org.kde.korganizer.Korganizer.xml korganizer_interface)
qt4_add_dbus_interface(todoapplet_SRCS org.kde.Korganizer.Calendar.xml calendar_interface)

kde4_add_ui_files(todoapplet_SRCS todoappletconfig.ui)

kde4_add_plugin(todoapplet ${todoapplet_SRCS})
target_link_libraries(todoapplet ${KDE4_PLASMA_LIBS} ${KDE4_KDEUI_LIBS})

install(TARGETS todoapplet DESTINATION ${PLUGIN_INSTALL_DIR})

install(FILES todoapplet-default.desktop DESTINATION ${SERVICES_INSTALL_DIR})
