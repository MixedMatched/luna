#ifndef STATE_H
#define STATE_H

#include "ModuleManager.h"
#include "StringPool.h"
#include <string>
#include <memory>

namespace luna
{
    class String;

    class State
    {
    public:
        State();

        State(const State&) = delete;
        void operator = (const State&) = delete;

        void AddModulePath(const std::string &path);

        void LoadModule(const std::string &module_name);
        void LoadString(const std::string &script_str);

        String *GetString(const std::string &str);

    private:
        std::unique_ptr<ModuleManager> module_manager_;
        std::unique_ptr<StringPool> string_pool_;
    };
} // namespace luna

#endif // STATE_H