这是一份为你精心准备的完整 README.md 文件。它结合了你作为物联网工程专业学生的开发背景，详细说明了如何处理跨平台路径、Cookie 绕过防爬虫以及合集下载等核心功能。
你可以直接将以下内容保存为 README.md 并推送到 GitHub。
# 全能网页视频下载器 (Universal Video Downloader)

![Platform](https://img.shields.io/badge/Platform-macOS%20%7C%20Windows-blue)
![Qt](https://img.shields.io/badge/Framework-Qt%206.6.2-green)
![License](https://img.shields.io/badge/License-Non--Commercial-orange)

这是一个基于 **Qt C++** 开发的跨平台视频下载工具。它深度集成了 `yt-dlp` 和 `FFmpeg`，旨在提供一个简洁、强力且能够绕过主流视频网站（如 B站、YouTube）反爬虫机制的图形化方案。

## 🌟 核心特性

- **跨平台架构**：针对 Apple Silicon (M1/M2/M3) 原生优化，支持 macOS Tahoe 及 Windows 10/11。
- **Cookie 注入技术**：支持从 Firefox、Chrome、Edge 和 Safari 提取登录凭证，轻松绕过 B站 480P 限制，解锁 1080P/4K 大会员画质。
- **合集批量下载**：支持 B站分P、番剧合集及 YouTube 播放列表一键解析，自动实现 `01_标题` 格式的重命名排版。
- **智能音视频合并**：自动检测环境中的 FFmpeg，解决高清视频流画面与声音分离的痛点，确保输出完整的 `.mp4`。
- **GitHub Actions 自动化**：项目配置了 CI/CD 流水线，代码推送后自动在云端构建 Windows 绿色版可执行程序。

---

## 🍎 macOS 使用教程 (开发环境)

作为物联网工程专业开发者，推荐在 macOS 下使用本地编译方式。

### 1. 准备工作
确保你的系统已安装 **Homebrew**，并执行以下命令安装底层引擎：
```bash
brew install yt-dlp ffmpeg cmake

2. 编译与运行
使用 CMake 进行外部构建：
# 进入源码目录
cd M3u8Downloader

# 配置并编译
cmake -S . -B build
cmake --build build

# 运行程序
open build/UniversalVideoDownloader.app

注：程序默认将视频下载至系统的 ~/Downloads 文件夹。
🪟 Windows 使用教程 (用户环境)
Windows 端无需配置开发环境，直接使用云端生成的构建产物。
1. 获取程序
1. 访问本仓库的 [Actions] 页面。
2. 点击最近一次成功的 "Windows Build" 工作流。
3. 在页面底部的 Artifacts 区域下载 Windows-Downloader-App 压缩包并解压。
2. 配置环境 (绿色免安装)
由于 Windows 权限限制，请将以下两个引擎文件手动放入与 UniversalVideoDownloader.exe 相同的文件夹内：
• yt-dlp.exe (下载地址)
• ffmpeg.exe (下载地址)
3. 运行
双击运行 UniversalVideoDownloader.exe 即可开始下载。
🍪 关键功能说明
🛡️ 如何绕过反爬虫 (Cookie)
1. 在程序界面的 "使用 Cookie" 下拉菜单中选择你常用的浏览器（推荐 Firefox，兼容性最佳）。
2. 确保你已经在该浏览器中登录了 B站 或目标网站的账号。
3. 点击“解析”，程序会自动借用浏览器的登录态，获取最高画质。
📂 合集模式
• 勾选 "合集模式" 后，粘贴 B站分P链接或 YouTube 列表链接。
• 程序会跳过逐集画质询问，直接锁定最佳画质进行批量下载，并自动按顺序编号，非常适合刷课或下载番剧。
🔊 修复“有画面无声音”
如果下载后视频没有声音，请检查：
• macOS: 确认是否执行了 brew install ffmpeg。
• Windows: 确认 ffmpeg.exe 是否与程序放在了同一个文件夹下。
🛠️ 技术架构
• 语言: C++23 / Qt 6
• 构建系统: CMake
• 核心组件: • QProcess: 异步调用底层 CLI 引擎。 • QStandardPaths: 跨平台路径自动映射。 • GitHub Actions: 基于 windows-latest 的自动化编译方案。
🤝 贡献
本项目主要由 ChoBits 开发，用于物联网工程项目实践及流媒体协议研究。
