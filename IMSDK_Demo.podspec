#
# Be sure to run `pod lib lint IMSDK_Demo.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'IMSDK_Demo'
  s.version          = '0.4.1'
  s.summary          = 'A short description of IMSDK_Demo.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/sunwangwang/IMSDK_Demo'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'sunwangwang' => 'sun.wang@vpclub.cn' }
  s.source           = { :git => 'https://github.com/sunwangwang/IMSDK_Demo.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'

#  s.source_files = 'IMSDK_Demo/Classes/**/*'
#  s.source_files = 'IMSDK_Demo/Classes/**/*.{h,m}'
  s.vendored_frameworks = 'IMSDK_Demo/Classes/*.framework'
   s.frameworks = 'UIKit', 'Foundation' , 'CoreMedia', 'AVFoundation', 'CFNetwork', 'Security'
    s.resource     = 'IMSDK_Demo/Assets/IMSDK.bundle'
#   s.resource_bundles = {
#     'IMSDK_Demo' => ['IMSDK_Demo/Assets/*']
#   }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
  
    s.dependency 'AFNetworking', '~> 4.0.1'
    s.dependency 'Masonry'
    s.dependency 'MBProgressHUD'
    s.dependency 'TZImagePickerController'
    s.dependency 'SDWebImage'
    s.dependency 'FMDB'
    s.dependency 'SocketRocket'
    s.dependency 'MJRefresh'
    s.dependency 'GKPhotoBrowser'
    s.dependency 'TTGTagCollectionView'
    s.dependency 'Protobuf'
    s.dependency 'EBBannerView'

  # s.resource_bundles = {
  #   'IMSDK_Demo' => ['IMSDK_Demo/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
