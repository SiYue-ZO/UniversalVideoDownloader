# 全能网页视频下载器 (Universal Video Downloader)

![Platform](https://img.shields.io/badge/Platform-macOS%20%7C%20Windows-blue)
![Qt](https://img.shields.io/badge/Framework-Qt%206-green)
![C++](https://img.shields.io/badge/Language-C%2B%2B%2020-orange)

基于 **Qt C++** 开发的跨平台视频下载工具，深度集成 `yt-dlp` 和 `FFmpeg`，提供简洁的图形化界面，支持绕过主流视频网站反爬虫机制。

---

## ✨ 核心特性

| 功能 | 说明 |
|------|------|
| 🖥️ **跨平台支持** | 原生支持 macOS (Apple Silicon) 和 Windows 10/11 |
| 🍪 **Cookie 注入** | 从浏览器提取登录凭证，解锁 B站 1080P/4K 大会员画质 |
| 📂 **合集批量下载** | 支持 B站分P、YouTube 播放列表一键下载，自动按序号命名 |
| 🔊 **智能音视频合并** | 自动调用 FFmpeg 合并分离的音视频流，输出完整 `.mp4` |
| ⬇️ **自动下载组件** | Windows 端首次启动自动下载 yt-dlp 和 ffmpeg（无需手动配置） |

---

## 📦 项目结构

```
├── main.cpp              # 程序入口
├── mainwindow.h/cpp      # 主窗口 UI 与业务逻辑
├── platformutils.h/cpp   # 平台抽象层（路径查找、平台检测）
├── toolmanager.h/cpp     # 工具下载管理器（自动下载/解压）
├── CMakeLists.txt        # 构建配置
└── .github/workflows/    # CI/CD 自动构建
```

---

## 🚀 快速开始

### macOS

#### 1. 安装依赖

```bash
# 安装 Homebrew（如未安装）
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# 安装必要工具
brew install yt-dlp ffmpeg cmake qt@6
```

#### 2. 编译运行

```bash
cd M3u8Downloader

# 配置并编译
cmake -S . -B build
cmake --build build

# 运行
open build/UniversalVideoDownloader.app
```

---

### Windows

#### 方式一：自动下载（推荐）

1. 从 GitHub Actions 下载最新构建产物并解压
2. 双击运行 `UniversalVideoDownloader.exe`
3. 程序会自动检测并提示下载缺失的 yt-dlp 和 ffmpeg

#### 方式二：手动配置

1. 下载 [yt-dlp.exe](https://github.com/yt-dlp/yt-dlp/releases/latest/download/yt-dlp.exe)
2. 下载 [ffmpeg.exe](https://github.com/BtbN/FFmpeg-Builds/releases/download/latest/ffmpeg-master-latest-win64-gpl.zip) 并解压
3. 将 `yt-dlp.exe` 和 `ffmpeg.exe` 放入程序所在目录

---

## 📖 使用指南

### 基本下载

1. 在输入框粘贴视频链接（支持 B站、YouTube 等）
2. 点击 **🔍 解析视频** 等待解析完成
3. 选择画质（推荐 **自动最佳画质**）
4. 点击 **⬇️ 开始下载**

### Cookie 绕过（解锁高清画质）

1. 在 **使用 Cookie** 下拉菜单选择你登录的浏览器
2. 确保浏览器已登录目标网站账号
3. 点击解析，程序会自动获取最高画质

> 💡 推荐使用 Firefox，兼容性最佳

### 合集批量下载

1. 勾选 **合集模式**
2. 粘贴 B站分P链接或 YouTube 播放列表链接
3. 点击解析，程序会自动锁定最佳画质
4. 点击下载，文件会按 `01_标题.mp4` 格式自动命名

---

## 🛠️ 技术架构

```
┌─────────────────────────────────────────────────┐
│                 MainWindow (Qt GUI)              │
│  ┌─────────────┐    ┌─────────────────────────┐ │
│  │  解析阶段    │    │       下载阶段           │ │
│  │  QProcess    │    │       QProcess          │ │
│  └──────┬──────┘    └───────────┬─────────────┘ │
│         │                        │               │
│  ┌──────┴────────────────────────┴─────────────┐ │
│  │            PlatformUtils                     │ │
│  │  • 平台检测    • 路径查找                     │ │
│  └──────────────────┬──────────────────────────┘ │
│                     │                             │
│  ┌──────────────────┴──────────────────────────┐ │
│  │            ToolManager                       │ │
│  │  • 自动下载    • 解压管理    • 状态通知        │ │
│  └──────────────────┬──────────────────────────┘ │
│                     │                             │
│  ┌──────────────────┴──────────────────────────┐ │
│  │        yt-dlp / FFmpeg (外部引擎)             │ │
│  └─────────────────────────────────────────────┘ │
└─────────────────────────────────────────────────┘
```

### 核心技术栈

- **语言**: C++20
- **GUI 框架**: Qt 6
- **构建系统**: CMake
- **外部引擎**: yt-dlp (视频解析/下载) + FFmpeg (音视频合并)
- **CI/CD**: GitHub Actions

### 关键设计

- **PlatformUtils**: 平台抽象层，封装跨平台路径查找逻辑
- **ToolManager**: 工具管理器，负责自动下载、解压和状态管理
- **QProcess**: 异步调用外部 CLI 引擎，避免阻塞 UI

---

## 🔧 常见问题

### 下载后没有声音？

- **macOS**: 确认已执行 `brew install ffmpeg`
- **Windows**: 确认 `ffmpeg.exe` 在程序目录下（或使用自动下载功能）

### B站解析失败？

- 确保浏览器已登录 B站账号
- 在 Cookie 下拉菜单选择正确的浏览器
- 尝试关闭浏览器后重试

### 下载速度慢？

- 检查网络连接
- 尝试更换画质（较低画质通常更快）
- 确认 yt-dlp 已更新到最新版本

---

## 📄 许可证

本项目仅供学习和个人使用，请勿用于商业用途。

---

## 🤝 贡献

欢迎提交 Issue 和 Pull Request！

---

<div align="center">
  <sub>Built with ❤️ by ChoBits</sub>
</div>
