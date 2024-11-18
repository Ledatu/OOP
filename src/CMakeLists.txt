
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

add_definitions(-std=c++17)

project(battleship)

add_executable(battleship
    main.cpp
    utils.h
    utils.cpp
    Field.h
    Field.cpp
    FieldCell.h
    FieldCell.cpp
    Ship.h
    Ship.cpp
    ShipCell.h
    ShipCell.cpp
    ShipManager.h
    ShipManager.cpp
    infoHolders/infoHolder.h
    infoHolders/SkillInfoHolder.h
    infoHolders/SkillInfoHolder.cpp
    exceptions/NoSkillsAvailable.h
    exceptions/NoSkillsAvailable.cpp
    exceptions/ShipNear.h
    exceptions/ShipNear.cpp
    exceptions/NotInField.h
    exceptions/NotInField.cpp
    skills/SkillManager.h
    skills/SkillManager.cpp
    skills/Skill.h
    skills/DoubleDamage.h
    skills/DoubleDamage.cpp
    skills/Scaner.h
    skills/Scaner.cpp
    skills/Shelling.h
    skills/Shelling.cpp
    skills/SkillFactory.h
    skills/DoubleDamageFactory.h
    skills/DoubleDamageFactory.cpp
    skills/ScanerFactory.h
    skills/ScanerFactory.cpp
    skills/ShellingFactory.h
    skills/ShellingFactory.cpp
)
