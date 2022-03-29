{
    "targets": [
        {
            "target_name": "game",
            "cflags!": ["-fno-exceptions"],
            "cflags_cc!": ["-fno-exceptions"],
            "sources": ["gamew.cc"],
            "include_dirs": [
                "<(module_root_dir)/game",
                "<(module_root_dir)/node_modules/node-addon-api"
            ],
            "defines": ["NAPI_DISABLE_CPP_EXCEPTIONS"],
            "libraries": ["<(module_root_dir)/game/libgame.a"],
        }
    ]
}
