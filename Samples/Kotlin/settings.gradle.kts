pluginManagement {
    repositories {
        google()
        mavenCentral()
        gradlePluginPortal()
    }
}

dependencyResolutionManagement {
    repositoriesMode.set(RepositoriesMode.FAIL_ON_PROJECT_REPOS)
    repositories {
        ivy {
            url = uri("../../SDK/Android")
            patternLayout { artifact("[artifact]-[revision].[ext]") }
            metadataSources { gradleMetadata() }
            content { includeGroup("com.ipcmobile.snapipc") }
        }
        google()
        mavenCentral()
    }
}

rootProject.name = "snapipc-native-android"
include(":app")
