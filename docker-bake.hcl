target "build" {
  target = "build"
  context = "."
  dockerfile = "ci/dockerfile"
  platforms = [
    "linux/amd64"
  ]
  ulimits = [
    "core=0"
  ]
}

target "artifacts" {
  inherits = ["build"]
  target     = "artifacts"
}

target "build-all-ci" {
  name = "build-${replace(item.image, ".", "-")}"
  inherits = ["artifacts"]
  tags = ["jdomagala:project-${item.image}"]
  args = {
    BASE_IMAGE = "${item.image}"
  }

  matrix = {
    item = [
      {
        image = "22.04"
      },
      {
        image = "24.04"
      }
    ]
  }
}
